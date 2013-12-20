#if 0
#include "XL/xlPort.h"
#include "XL/xlLog.h"
#include "XL/xlError.h"
#include "XL/xlSet.h"
#include "XL/xlParser.h"
#include "XL/xlUtils.h"
#include "XL/xlVector.h"
#include "XL/xlMatrix.h"
#include "XL/xlMaterial.h"
#include "XL/xlSurface.h"
#include "XL/xlObject.h"
#include "XL/xlModel.h"
#include "XL/xlCamera.h"
#include "XL/xlOperator.h"
#include "XL/xlData.h"
//#include <ode/ode.h>

#include "XL/id.h"

#define prts(t) sizeof(XLPort ## t)

idVoidCreate();

idVoidInit(XL, port);

idVoidTerm(XL, port);

idVoidDestroy();

idDefineAPI(xl, XL, port, Port, idCreate, idInit, idTerm, idDestroy, ID_SMALL_STORE);

idStoreDef(xl, XL, port, Port);

idTypeDef(xl, XL, port, Prt);

void
xlPortLoad(XLuint id, const char *filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "rb");
	if(stream)
	{
		XLport *port;

		port = store[id];

		xlFileRead(&port->header, 1, prts(Header), stream);

		xlLog(L"%s: triggers: %i\n", filepath, port->header.triggers);
		port->body.triggers = xlAlloc(port->header.triggers * prts(Trigger));
		xlFileRead(port->body.triggers, port->header.triggers, prts(Trigger), stream);

		xlLog(L"%s: actions: %i\n", filepath, port->header.actions);
		port->body.actions = xlAlloc(port->header.actions * prts(Action));
		xlFileRead(port->body.actions, port->header.actions, prts(Action), stream);

		xlLog(L"%s: units: %i\n", filepath, port->header.units);
		port->body.units = xlAlloc(port->header.units * prts(Unit));
		xlFileRead(port->body.units, port->header.units, prts(Unit), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_INVALID_PATH);
}

static
void
idUnload(XLport *port)
{
	xlFree(port->body.units);
	xlFree(port->body.actions);
	xlFree(port->body.triggers);
}

idUnloadDef(xl, XL, port, Port, idUnload);

void
xlPortCompile(XLuint id, const char *filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "r");
	if(stream)
	{
		XLport *port;
		XLstringbuffer buffer;
		XLPortTrigger *triggers;
		XLPortAction *actions;
		XLPortUnit *units;
		XLuint i;

		port = store[id];

		xlFileGetAttributeu(L"triggers", &port->header.triggers, stream);
		xlLog(L"%s: triggers: %i\n", filepath, port->header.triggers);
		port->body.triggers = xlAlloc(port->header.triggers * prts(Trigger));
		triggers = port->body.triggers;
		for(i = 0; i < port->header.triggers; i++)
		{
			xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
			if(xlStringEqual(buffer, L"keyboard\n"))
			{
				triggers[i].type = XL_PORT_TRIGGER_KEYBOARD;
				xlFileGetAttributewc(L"key", &triggers[i].trigger.keyboard.key, stream);
			}
			else if(xlStringEqual(buffer, L"material\n"))
			{
				triggers[i].type = XL_PORT_TRIGGER_MATERIAL;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"object\n"))
				{
					xlFileGetAttributeu(L"material", &triggers[i].trigger.material.material, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				}
				if(xlStringEqual(buffer, L"property\n"))
				{
					triggers[i].trigger.material.type = XL_PORT_TRIGGER_MATERIAL_PROPERTY;
					xlFileGetAttributeu(L"property", &triggers[i].trigger.material.trigger.property, stream);
				}
			}
			else if(xlStringEqual(buffer, L"surface\n"))
			{
				triggers[i].type = XL_PORT_TRIGGER_SURFACE;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"object\n"))
				{
					xlFileGetAttributeu(L"surface", &triggers[i].trigger.surface.surface, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				}
				if(xlStringEqual(buffer, L"action\n"))
				{
					triggers[i].trigger.surface.type = XL_PORT_TRIGGER_SURFACE_ACTION;
					xlFileGetAttributeu(L"action", &triggers[i].trigger.surface.trigger.action, stream);
				}
				else if(xlStringEqual(buffer, L"frame\n"))
				{
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					if(xlStringEqual(buffer, L"loop\n"))
					{
						triggers[i].trigger.surface.type = XL_PORT_TRIGGER_SURFACE_FRAME_LOOP;
						xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					}
					else
						triggers[i].trigger.surface.type = XL_PORT_TRIGGER_SURFACE_FRAME;
					xlFileScanAttributeu(buffer, L"frame", &triggers[i].trigger.surface.trigger.frame);
				}
				else if(xlStringEqual(buffer, L"actionframe\n"))
				{
					xlFileGetAttributeu(L"action", &triggers[i].trigger.surface.trigger.action, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					if(xlStringEqual(buffer, L"loop\n"))
					{
						triggers[i].trigger.surface.type = XL_PORT_TRIGGER_SURFACE_ACTION_FRAME_LOOP;
						xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					}
					else
						triggers[i].trigger.surface.type = XL_PORT_TRIGGER_SURFACE_ACTION_FRAME;
					xlFileScanAttributeu(buffer, L"frame", &triggers[i].trigger.surface.trigger.frame);
				}
			}
			else if(xlStringEqual(buffer, L"model\n"))
			{
				triggers[i].type = XL_PORT_TRIGGER_MODEL;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"action\n"))
				{
					triggers[i].trigger.model.type = XL_PORT_TRIGGER_MODEL_ACTION;
					xlFileGetAttributeu(L"action", &triggers[i].trigger.model.trigger.action, stream);
				}
				else if(xlStringEqual(buffer, L"frame\n"))
				{
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					if(xlStringEqual(buffer, L"loop\n"))
					{
						triggers[i].trigger.model.type = XL_PORT_TRIGGER_MODEL_FRAME_LOOP;
						xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					}
					else
						triggers[i].trigger.model.type = XL_PORT_TRIGGER_MODEL_FRAME;
					xlFileScanAttributeu(buffer, L"frame", &triggers[i].trigger.model.trigger.frame);
				}
				else if(xlStringEqual(buffer, L"actionframe\n"))
				{
					xlFileGetAttributeu(L"action", &triggers[i].trigger.model.trigger.action, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					if(xlStringEqual(buffer, L"loop\n"))
					{
						triggers[i].trigger.model.type = XL_PORT_TRIGGER_MODEL_ACTION_FRAME_LOOP;
						xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					}
					else
						triggers[i].trigger.model.type = XL_PORT_TRIGGER_MODEL_ACTION_FRAME;
					xlFileScanAttributeu(buffer, L"frame", &triggers[i].trigger.model.trigger.frame);
				}
			}
			else if(xlStringEqual(buffer, L"camera\n"))
			{
				triggers[i].type = XL_PORT_TRIGGER_CAMERA;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"property\n"))
				{
					triggers[i].trigger.camera.type = XL_PORT_TRIGGER_CAMERA_PROPERTY;
					xlFileGetAttributeu(L"property", &triggers[i].trigger.camera.trigger.property, stream);
				}
			}
			else if(xlStringEqual(buffer, L"operator\n"))
			{
				triggers[i].type = XL_PORT_TRIGGER_OPERATOR;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"action\n"))
				{
					triggers[i].trigger.operator.type = XL_PORT_TRIGGER_OPERATOR_ACTION;
					xlFileGetAttributeu(L"action", &triggers[i].trigger.operator.trigger.action, stream);
				}
				else if(xlStringEqual(buffer, L"frame\n"))
				{
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					if(xlStringEqual(buffer, L"loop\n"))
					{
						triggers[i].trigger.operator.type = XL_PORT_TRIGGER_OPERATOR_FRAME_LOOP;
						xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					}
					else
						triggers[i].trigger.operator.type = XL_PORT_TRIGGER_OPERATOR_FRAME;
					xlFileScanAttributeu(buffer, L"frame", &triggers[i].trigger.operator.trigger.frame);
				}
				else if(xlStringEqual(buffer, L"actionframe\n"))
				{
					xlFileGetAttributeu(L"action", &triggers[i].trigger.operator.trigger.action, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					if(xlStringEqual(buffer, L"loop\n"))
					{
						triggers[i].trigger.operator.type = XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME_LOOP;
						xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
					}
					else
						triggers[i].trigger.operator.type = XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME;
					xlFileScanAttributeu(buffer, L"frame", &triggers[i].trigger.operator.trigger.frame);
				}
			}
		}

		xlFileGetAttributeu(L"actions", &port->header.actions, stream);
		xlLog(L"%s: actions: %i\n", filepath, port->header.actions);
		port->body.actions = xlAlloc(port->header.actions * prts(Action));
		actions = port->body.actions;
		for(i = 0; i < port->header.actions; i++)
		{
			xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
			if(xlStringEqual(buffer, L"material\n"))
			{
				actions[i].type = XL_PORT_ACTION_MATERIAL;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"object\n"))
				{
					xlFileGetAttributeu(L"material", &actions[i].action.material.material, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				}
				if(xlStringEqual(buffer, L"property\n"))
				{
					actions[i].action.material.type = XL_PORT_ACTION_MATERIAL_PROPERTY;
					xlFileGetAttributeu(L"property", &actions[i].action.material.action.property, stream);
				}
				else if(xlStringEqual(buffer, L"matrix\n"))
				{
					actions[i].action.material.type = XL_PORT_ACTION_MATERIAL_MATRIX;
					xlFileGetAttribute16fv(L"matrix", actions[i].action.material.action.matrix, stream);
				}
			}
			else if(xlStringEqual(buffer, L"surface\n"))
			{
				actions[i].type = XL_PORT_ACTION_SURFACE;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"object\n"))
				{
					xlFileGetAttributeu(L"surface", &actions[i].action.surface.surface, stream);
					xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				}
				if(xlStringEqual(buffer, L"action\n"))
				{
					actions[i].action.surface.type = XL_PORT_ACTION_SURFACE_ACTION;
					xlFileGetAttributeu(L"action", &actions[i].action.surface.action.action, stream);
				}
				else if(xlStringEqual(buffer, L"frame\n"))
				{
					actions[i].action.surface.type = XL_PORT_ACTION_SURFACE_FRAME;
					xlFileGetAttributeu(L"frame", &actions[i].action.surface.action.frame, stream);
				}
				else if(xlStringEqual(buffer, L"actionframe\n"))
				{
					actions[i].action.surface.type = XL_PORT_ACTION_SURFACE_ACTION_FRAME;
					xlFileGetAttributeu(L"action", &actions[i].action.surface.action.action, stream);
					xlFileGetAttributeu(L"frame", &actions[i].action.surface.action.frame, stream);
				}
			}
			else if(xlStringEqual(buffer, L"object\n"))
			{
				actions[i].type = XL_PORT_ACTION_OBJECT;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"matrix\n"))
				{
					actions[i].action.object.type = XL_PORT_ACTION_OBJECT_MATRIX;
					xlFileGetAttribute16fv(L"matrix", actions[i].action.object.action.matrix, stream);
				}
			}
			else if(xlStringEqual(buffer, L"model\n"))
			{
				actions[i].type = XL_PORT_ACTION_MODEL;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"action\n"))
				{
					actions[i].action.model.type = XL_PORT_ACTION_MODEL_ACTION;
					xlFileGetAttributeu(L"action", &actions[i].action.model.action.action, stream);
				}
				else if(xlStringEqual(buffer, L"frame\n"))
				{
					actions[i].action.model.type = XL_PORT_ACTION_MODEL_FRAME;
					xlFileGetAttributeu(L"frame", &actions[i].action.model.action.frame, stream);
				}
				else if(xlStringEqual(buffer, L"actionframe\n"))
				{
					actions[i].action.model.type = XL_PORT_ACTION_MODEL_ACTION_FRAME;
					xlFileGetAttributeu(L"action", &actions[i].action.model.action.action, stream);
					xlFileGetAttributeu(L"frame", &actions[i].action.model.action.frame, stream);
				}
			}
			else if(xlStringEqual(buffer, L"camera\n"))
			{
				actions[i].type = XL_PORT_ACTION_CAMERA;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"property\n"))
				{
					actions[i].action.camera.type = XL_PORT_ACTION_CAMERA_PROPERTY;
					xlFileGetAttributeu(L"property", &actions[i].action.camera.action.property, stream);
				}
				else if(xlStringEqual(buffer, L"matrix\n"))
				{
					actions[i].action.camera.type = XL_PORT_ACTION_CAMERA_MATRIX;
					xlFileGetAttribute16fv(L"matrix", actions[i].action.camera.action.matrix, stream);
				}
			}
			else if(xlStringEqual(buffer, L"operator\n"))
			{
				actions[i].type = XL_PORT_ACTION_OPERATOR;
				xlFileGetString(buffer, XL_STRING_BUFFER_SIZE, stream);
				if(xlStringEqual(buffer, L"action\n"))
				{
					actions[i].action.operator.type = XL_PORT_ACTION_OPERATOR_ACTION;
					xlFileGetAttributeu(L"action", &actions[i].action.operator.action.action, stream);
				}
				else if(xlStringEqual(buffer, L"frame\n"))
				{
					actions[i].action.operator.type = XL_PORT_ACTION_OPERATOR_FRAME;
					xlFileGetAttributeu(L"frame", &actions[i].action.operator.action.frame, stream);
				}
				else if(xlStringEqual(buffer, L"actionframe\n"))
				{
					actions[i].action.operator.type = XL_PORT_ACTION_OPERATOR_ACTION_FRAME;
					xlFileGetAttributeu(L"action", &actions[i].action.operator.action.action, stream);
					xlFileGetAttributeu(L"frame", &actions[i].action.operator.action.frame, stream);
				}
			}
		}

		xlFileGetAttributeu(L"units", &port->header.units, stream);
		xlLog(L"%s: units: %i\n", filepath, port->header.units);
		port->body.units = xlAlloc(port->header.units * prts(Unit));
		units = port->body.units;
		for(i = 0; i < port->header.units; i++)
		{
			xlFileGetAttributew(L"name", units[i].name, stream);
			xlFileGetAttributel(L"triggers", &units[i].triggersstart, &units[i].triggers, stream);
			xlFileGetAttributel(L"actions", &units[i].actionsstart, &units[i].actions, stream);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_INVALID_PATH);
}

void
xlPortDecompile(XLuint id, const char *filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "w");
	if(stream)
	{
		XLport *port;
		XLPortTrigger *triggers;
		XLPortAction *actions;
		XLPortUnit *units;
		XLuint i;

		port = store[id];

		triggers = port->body.triggers;
		xlFilePrintAttributeu(stream, L"triggers", port->header.triggers);
		for(i = 0; i < port->header.triggers; i++)
		{
			switch(triggers[i].type)
			{
				case XL_PORT_TRIGGER_KEYBOARD:
					xlFilePrintStringFormatted(stream, L"%s\n", L"keyboard");
					xlFilePrintAttributewc(stream, L"key", triggers[i].trigger.keyboard.key);
					break;
				case XL_PORT_TRIGGER_MATERIAL:
					xlFilePrintStringFormatted(stream, L"%s\n", L"material");
					switch(triggers[i].trigger.material.type)
					{
						case XL_PORT_TRIGGER_MATERIAL_PROPERTY:
							xlFilePrintStringFormatted(stream, L"%s\n", L"property");
							xlFilePrintAttributeu(stream, L"property", triggers[i].trigger.material.trigger.property);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_TRIGGER_SURFACE:
					xlFilePrintStringFormatted(stream, L"%s\n", L"surface");
					switch(triggers[i].trigger.surface.type)
					{
						case XL_PORT_TRIGGER_SURFACE_ACTION:
							xlFilePrintStringFormatted(stream, L"%s\n", L"action");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.surface.trigger.action);
							break;
						case XL_PORT_TRIGGER_SURFACE_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.surface.trigger.frame);
							break;
						case XL_PORT_TRIGGER_SURFACE_FRAME_LOOP:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintStringFormatted(stream, L"%s\n", L"loop");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.surface.trigger.frame);
							break;
						case XL_PORT_TRIGGER_SURFACE_ACTION_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.surface.trigger.action);
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.surface.trigger.frame);
							break;
						case XL_PORT_TRIGGER_SURFACE_ACTION_FRAME_LOOP:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.surface.trigger.action);
							xlFilePrintStringFormatted(stream, L"%s\n", L"loop");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.surface.trigger.frame);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_TRIGGER_MODEL:
					xlFilePrintStringFormatted(stream, L"%s\n", L"model");
					switch(triggers[i].trigger.model.type)
					{
						case XL_PORT_TRIGGER_MODEL_ACTION:
							xlFilePrintStringFormatted(stream, L"%s\n", L"action");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.model.trigger.action);
							break;
						case XL_PORT_TRIGGER_MODEL_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.model.trigger.frame);
							break;
						case XL_PORT_TRIGGER_MODEL_FRAME_LOOP:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintStringFormatted(stream, L"%s\n", L"loop");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.model.trigger.frame);
							break;
						case XL_PORT_TRIGGER_MODEL_ACTION_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.model.trigger.action);
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.model.trigger.frame);
							break;
						case XL_PORT_TRIGGER_MODEL_ACTION_FRAME_LOOP:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.model.trigger.action);
							xlFilePrintStringFormatted(stream, L"%s\n", L"loop");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.model.trigger.frame);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_TRIGGER_CAMERA:
					xlFilePrintStringFormatted(stream, L"%s\n", L"camera");
					switch(triggers[i].trigger.camera.type)
					{
						case XL_PORT_TRIGGER_CAMERA_PROPERTY:
							xlFilePrintStringFormatted(stream, L"%s\n", L"property");
							xlFilePrintAttributeu(stream, L"property", triggers[i].trigger.camera.trigger.property);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_TRIGGER_OPERATOR:
					xlFilePrintStringFormatted(stream, L"%s\n", L"operator");
					switch(triggers[i].trigger.operator.type)
					{
						case XL_PORT_TRIGGER_OPERATOR_ACTION:
							xlFilePrintStringFormatted(stream, L"%s\n", L"action");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.operator.trigger.action);
							break;
						case XL_PORT_TRIGGER_OPERATOR_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.operator.trigger.frame);
							break;
						case XL_PORT_TRIGGER_OPERATOR_FRAME_LOOP:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintStringFormatted(stream, L"%s\n", L"loop");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.operator.trigger.frame);
							break;
						case XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.operator.trigger.action);
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.operator.trigger.frame);
							break;
						case XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME_LOOP:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", triggers[i].trigger.operator.trigger.action);
							xlFilePrintStringFormatted(stream, L"%s\n", L"loop");
							xlFilePrintAttributeu(stream, L"frame", triggers[i].trigger.operator.trigger.frame);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				default:
					xlSetError(XL_ERROR_INVALID_DATA);
			}
		}

		actions = port->body.actions;
		xlFilePrintAttributeu(stream, L"actions", port->header.actions);
		for(i = 0; i < port->header.actions; i++)
		{
			switch(actions[i].type)
			{
				case XL_PORT_ACTION_MATERIAL:
					xlFilePrintStringFormatted(stream, L"%s\n", L"material");
					if(port->type != XL_PORT_MATERIAL)
					{
							xlFilePrintStringFormatted(stream, L"%s\n", L"object");
							xlFilePrintAttributeu(stream, L"material", actions[i].action.material.material);
					}
					switch(actions[i].action.material.type)
					{
						case XL_PORT_ACTION_MATERIAL_PROPERTY:
							xlFilePrintStringFormatted(stream, L"%s\n", L"property");
							xlFilePrintAttributeu(stream, L"property", actions[i].action.material.action.property);
							break;
						case XL_PORT_ACTION_MATERIAL_MATRIX:
							xlFilePrintStringFormatted(stream, L"%s\n", L"matrix");
							xlFilePrintAttribute16fv(stream, L"matrix", actions[i].action.material.action.matrix);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_ACTION_SURFACE:
					xlFilePrintStringFormatted(stream, L"%s\n", L"surface");
					if(port->type != XL_PORT_SURFACE)
					{
							xlFilePrintStringFormatted(stream, L"%s\n", L"object");
							xlFilePrintAttributeu(stream, L"surface", actions[i].action.surface.surface);
					}
					switch(actions[i].action.surface.type)
					{
						case XL_PORT_ACTION_SURFACE_ACTION:
							xlFilePrintStringFormatted(stream, L"%s\n", L"action");
							xlFilePrintAttributeu(stream, L"action", actions[i].action.surface.action.action);
							break;
						case XL_PORT_ACTION_SURFACE_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintAttributeu(stream, L"frame", actions[i].action.surface.action.frame);
							break;
						case XL_PORT_ACTION_SURFACE_ACTION_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", actions[i].action.surface.action.action);
							xlFilePrintAttributeu(stream, L"frame", actions[i].action.surface.action.frame);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_ACTION_OBJECT:
					xlFilePrintStringFormatted(stream, L"%s\n", L"object");
					switch(actions[i].action.object.type)
					{
						case XL_PORT_ACTION_OBJECT_MATRIX:
							xlFilePrintStringFormatted(stream, L"%s\n", L"matrix");
							xlFilePrintAttribute16fv(stream, L"matrix", actions[i].action.object.action.matrix);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_ACTION_MODEL:
					xlFilePrintStringFormatted(stream, L"%s\n", L"model");
					switch(actions[i].action.model.type)
					{
						case XL_PORT_ACTION_MODEL_ACTION:
							xlFilePrintStringFormatted(stream, L"%s\n", L"action");
							xlFilePrintAttributeu(stream, L"action", actions[i].action.model.action.action);
							break;
						case XL_PORT_ACTION_MODEL_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintAttributeu(stream, L"frame", actions[i].action.model.action.frame);
							break;
						case XL_PORT_ACTION_MODEL_ACTION_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", actions[i].action.model.action.action);
							xlFilePrintAttributeu(stream, L"frame", actions[i].action.model.action.frame);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_ACTION_CAMERA:
					xlFilePrintStringFormatted(stream, L"%s\n", L"camera");
					switch(actions[i].action.camera.type)
					{
						case XL_PORT_ACTION_CAMERA_PROPERTY:
							xlFilePrintStringFormatted(stream, L"%s\n", L"property");
							xlFilePrintAttributeu(stream, L"property", actions[i].action.camera.action.property);
							break;
						case XL_PORT_ACTION_CAMERA_MATRIX:
							xlFilePrintStringFormatted(stream, L"%s\n", L"matrix");
							xlFilePrintAttribute16fv(stream, L"matrix", actions[i].action.camera.action.matrix);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				case XL_PORT_ACTION_OPERATOR:
					xlFilePrintStringFormatted(stream, L"%s\n", L"operator");
					switch(actions[i].action.operator.type)
					{
						case XL_PORT_ACTION_OPERATOR_ACTION:
							xlFilePrintStringFormatted(stream, L"%s\n", L"action");
							xlFilePrintAttributeu(stream, L"action", actions[i].action.operator.action.action);
							break;
						case XL_PORT_ACTION_OPERATOR_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"frame");
							xlFilePrintAttributeu(stream, L"frame", actions[i].action.operator.action.frame);
							break;
						case XL_PORT_ACTION_OPERATOR_ACTION_FRAME:
							xlFilePrintStringFormatted(stream, L"%s\n", L"actionframe");
							xlFilePrintAttributeu(stream, L"action", actions[i].action.operator.action.action);
							xlFilePrintAttributeu(stream, L"frame", actions[i].action.operator.action.frame);
							break;
						default:
							xlSetError(XL_ERROR_INVALID_DATA);
					}
					break;
				default:
					xlSetError(XL_ERROR_INVALID_DATA);
			}
		}

		units = port->body.units;
		xlFilePrintAttributeu(stream, L"units", port->header.units);
		for(i = 0; i < port->header.units; i++)
		{
			xlFilePrintAttributew(stream, L"name", units[i].name);
			xlFilePrintAttributel(stream, L"triggers", units[i].triggersstart, units[i].triggers);
			xlFilePrintAttributel(stream, L"actions", units[i].actionsstart, units[i].actions);
		}

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_INVALID_PATH);
}

void
xlPortSave(XLuint id, const char *filepath)
{
	XLfile *stream;

	stream = xlFileOpen(filepath, "wb");
	if(stream)
	{
		XLport *port;

		port = store[id];

		xlFileWrite(&port->header, 1, prts(Header), stream);

		xlFileWrite(port->body.triggers, port->header.triggers, prts(Trigger), stream);
		xlFileWrite(port->body.actions, port->header.actions, prts(Action), stream);
		xlFileWrite(port->body.units, port->header.units, prts(Unit), stream);

		xlFileClose(stream);
	}
	else
		xlSetError(XL_ERROR_INVALID_PATH);
}

XLuint
xlPortTriggers(XLuint id)
{
	XLport *port;

	port = store[id];

	return port->header.triggers;
}

XLuint
xlPortActions(XLuint id)
{
	XLport *port;

	port = store[id];

	return port->header.actions;
}

XLuint
xlPortUnits(XLuint id)
{
	XLport *port;

	port = store[id];

	return port->header.units;
}


XLuint
xlPortTriggerType(XLuint id, XLuint trigger)
{
	XLport *port;

	port = store[id];

	return port->body.triggers[trigger].type;
}

XLuint
xlPortActionType(XLuint id, XLuint action)
{
	XLport *port;

	port = store[id];

	return port->body.actions[action].type;
}

XLuint
xlPortUnitId(XLuint id, const wchar_t *name)
{
	XLport *port;
	XLuint i;

	port = store[id];

	for(i = 0; !xlStringEqual(port->body.units[i].name, name); i++);
	return i;
}

const wchar_t *
xlPortUnitName(XLuint id, XLuint unit)
{
	XLport *port;

	port = store[id];

	return port->body.units[unit].name;
}

void
xlPortSetId(XLuint id, XLuint type, XLuint object)
{
	XLport *port;

	port = store[id];

	port->type = type;
	port->id = object;
}

void
xlPortSetMaterial(XLuint id, XLuint material)
{
	XLport *port;

	port = store[id];

	port->type = XL_PORT_MATERIAL;
	port->id = material;
}

void
xlPortSetSurface(XLuint id, XLuint surface)
{
	XLport *port;

	port = store[id];

	port->type = XL_PORT_SURFACE;
	port->id = surface;
}

void
xlPortSetObject(XLuint id, XLuint object)
{
	XLport *port;

	port = store[id];

	port->type = XL_PORT_OBJECT;
	port->id = object;
}

void
xlPortSetModel(XLuint id, XLuint model)
{
	XLport *port;

	port = store[id];

	port->type = XL_PORT_MODEL;
	port->id = model;
}

void
xlPortSetCamera(XLuint id, XLuint camera)
{
	XLport *port;

	port = store[id];

	port->type = XL_PORT_CAMERA;
	port->id = camera;
}

void
xlPortSetOperator(XLuint id, XLuint operator)
{
	XLport *port;

	port = store[id];

	port->type = XL_PORT_OPERATOR;
	port->id = operator;
}

void
xlPortSetKeyboard(XLuint id, wchar_t key)
{
	XLport *port;

	port = store[id];

	port->key = key;
}

XLuint
xlPortIdType(XLuint id)
{
	XLport *port;

	port = store[id];

	return port->type;
}

XLuint
xlPortId(XLuint id)
{
	XLport *port;

	port = store[id];

	return port->id;
}

static
void
_xlPortMaterialActionUnitAction(XLport *port, XLuint unit, XLuint action)
{
	XLuint material = 0, property;
	float matrix[16];

	switch(port->type)
	{
		case XL_PORT_MATERIAL:
			material = port->id;
			break;
		case XL_PORT_SURFACE:
			material = xlSurfaceMaterial(port->id);
			break;
		case XL_PORT_OBJECT:
			material= xlObjectMaterial(port->id, port->body.actions[action].action.material.material);
			break;
		case XL_PORT_MODEL:
			material = xlObjectMaterial(xlModelObject(port->id), port->body.actions[action].action.material.material);
			break;
		default:
			break;
	}
	switch(port->body.actions[action].action.material.type)
	{
		case XL_PORT_ACTION_MATERIAL_PROPERTY:
			xlMaterialSetProperty(material, port->body.actions[action].action.material.action.property);
			break;
		case XL_PORT_ACTION_MATERIAL_MATRIX:
			property = xlMaterialProperty(material);
			xlMatrixCopy(matrix, xlMaterialPropertyMatrix(material, property));
			xlMatrixMult(matrix, port->body.actions[action].action.material.action.matrix);
			xlMaterialSetPropertyMatrix(material, property, matrix);
			break;
		default:
			break;
	}
}

static
void
_xlPortSurfaceActionUnitAction(XLport *port, XLuint unit, XLuint action)
{
	XLuint surface = 0;

	switch(port->type)
	{
		case XL_PORT_SURFACE:
			surface = port->id;
			break;
		case XL_PORT_OBJECT:
			surface= xlObjectMaterial(port->id, port->body.actions[action].action.surface.surface);
			break;
		case XL_PORT_MODEL:
			surface = xlObjectMaterial(xlModelObject(port->id), port->body.actions[action].action.surface.surface);
			break;
		default:
			break;
	}
	switch(port->body.actions[action].action.surface.type)
	{
		case XL_PORT_ACTION_SURFACE_ACTION:
			xlSurfaceSetAction(surface, port->body.actions[action].action.surface.action.action);
			break;
		case XL_PORT_ACTION_SURFACE_FRAME:
			xlSurfaceSetActionFrame(surface, port->body.actions[action].action.surface.action.frame);
			break;
		case XL_PORT_ACTION_SURFACE_ACTION_FRAME:
			xlSurfaceSetAction(surface, port->body.actions[action].action.surface.action.action);
			xlSurfaceSetActionFrame(surface, port->body.actions[action].action.surface.action.frame);
			break;
		default:
			break;
	}
}

static
void
_xlPortObjectActionUnitAction(XLport *port, XLuint unit, XLuint action)
{
	XLuint object = 0;
	float matrix[16];

	switch(port->type)
	{
		case XL_PORT_OBJECT:
			object = port->id;
			break;
		case XL_PORT_MODEL:
			object = xlModelObject(port->id);
			break;
		default:
			break;
	}
	switch(port->body.actions[action].action.object.type)
	{
		case XL_PORT_ACTION_OBJECT_MATRIX:
			xlMatrixCopy(matrix, xlObjectMatrix(object));
			xlMatrixMult(matrix, port->body.actions[action].action.object.action.matrix);
			xlObjectSetMatrix(object, matrix);
			break;
		default:
			break;
	}
}

static
void
_xlPortModelActionUnitAction(XLport *port, XLuint unit, XLuint action)
{
	switch(port->body.actions[action].action.model.type)
	{
		case XL_PORT_ACTION_MODEL_ACTION:
			xlModelSetAction(port->id, port->body.actions[action].action.model.action.action);
			break;
		case XL_PORT_ACTION_MODEL_FRAME:
			xlModelSetActionFrame(port->id, port->body.actions[action].action.model.action.frame);
			break;
		case XL_PORT_ACTION_MODEL_ACTION_FRAME:
			xlModelSetAction(port->id, port->body.actions[action].action.model.action.action);
			xlModelSetActionFrame(port->id, port->body.actions[action].action.model.action.frame);
			break;
		default:
			break;
	}
}

static
void
_xlPortCameraActionUnitAction(XLport *port, XLuint unit, XLuint action)
{
	XLuint camera = 0, property;
	float matrix[16];

	switch(port->type)
	{
		case XL_PORT_CAMERA:
			camera = port->id;
			break;
		case XL_PORT_OPERATOR:
			camera = xlOperatorCamera(port->id);
			break;
		default:
			break;
	}
	switch(port->body.actions[action].action.camera.type)
	{
		case XL_PORT_ACTION_CAMERA_PROPERTY:
			xlCameraSetProperty(camera, port->body.actions[action].action.camera.action.property);
			break;
		case XL_PORT_ACTION_CAMERA_MATRIX:
			property = xlCameraProperty(camera);
			xlMatrixCopy(matrix, port->body.actions[action].action.camera.action.matrix);
			xlMatrixMult(matrix, xlCameraPropertyMatrix(camera, property));
			xlCameraSetPropertyMatrix(camera, property, matrix);
			break;
		default:
			break;
	}
}

static
void
_xlPortOperatorActionUnitAction(XLport *port, XLuint unit, XLuint action)
{
	switch(port->body.actions[action].action.operator.type)
	{
		case XL_PORT_ACTION_OPERATOR_ACTION:
			xlOperatorSetAction(port->id, port->body.actions[action].action.operator.action.action);
			break;
		case XL_PORT_ACTION_OPERATOR_FRAME:
			xlOperatorSetActionFrame(port->id, port->body.actions[action].action.operator.action.frame);
			break;
		case XL_PORT_ACTION_OPERATOR_ACTION_FRAME:
			xlOperatorSetAction(port->id, port->body.actions[action].action.operator.action.action);
			xlOperatorSetActionFrame(port->id, port->body.actions[action].action.operator.action.frame);
			break;
		default:
			break;
	}
}

static
void
_xlPortActionUnit(XLport *port, XLuint unit)
{
	XLuint i;

	for(i = port->body.units[unit].actionsstart; i < port->body.units[unit].actionsstart + port->body.units[unit].actions; i++)
	{
		switch(port->body.actions[i].type)
		{
			case XL_PORT_ACTION_MATERIAL:
				_xlPortMaterialActionUnitAction(port, unit, i);
				break;
			case XL_PORT_ACTION_SURFACE:
				_xlPortSurfaceActionUnitAction(port, unit, i);
				break;
			case XL_PORT_ACTION_OBJECT:
				_xlPortObjectActionUnitAction(port, unit, i);
				break;
			case XL_PORT_ACTION_MODEL:
				_xlPortModelActionUnitAction(port, unit, i);
				break;
			case XL_PORT_ACTION_CAMERA:
				_xlPortCameraActionUnitAction(port, unit, i);
				break;
			case XL_PORT_ACTION_OPERATOR:
				_xlPortOperatorActionUnitAction(port, unit, i);
				break;
			default:
				break;
		}
	}
}

void
xlPortActionUnit(XLuint id, XLuint unit)
{
	XLport *port;

	port = store[id];

	_xlPortActionUnit(port, unit);
}

static
XLuint
_xlPortTriggerIdUnit(XLport *port, XLuint unit)
{
	XLuint trigger;
	XLuint i, camera = 0, material = 0, surface = 0, property, action, frame;

	trigger = 0;
	for(i = port->body.units[unit].triggersstart; i < port->body.units[unit].triggersstart + port->body.units[unit].triggers; i++)
	{ 
		switch(port->body.triggers[i].type)
		{
			case XL_PORT_TRIGGER_MATERIAL:
				switch(port->type)
				{
					case XL_PORT_MATERIAL:
						material = port->id;
						break;
					case XL_PORT_SURFACE:
						material = xlSurfaceMaterial(port->id);
						break;
					case XL_PORT_OBJECT:
						material = xlObjectMaterial(port->id, port->body.triggers[i].trigger.material.material);
						break;
					case XL_PORT_MODEL:
						material = xlObjectMaterial(xlModelObject(port->id), port->body.triggers[i].trigger.material.material);
						break;
					default:
						break;
				}
				switch(port->body.triggers[i].trigger.material.type)
				{
					case XL_PORT_TRIGGER_MATERIAL_PROPERTY:
						property = xlMaterialProperty(material);
						if(property == port->body.triggers[i].trigger.material.trigger.property)
							trigger = 1;
						break;
					default:
						break;
				}
				break;
			case XL_PORT_TRIGGER_SURFACE:
				switch(port->type)
				{
					case XL_PORT_SURFACE:
						surface = port->id;
						break;
					case XL_PORT_OBJECT:
						surface = xlObjectMaterial(port->id, port->body.triggers[i].trigger.surface.surface);
						break;
					case XL_PORT_MODEL:
						surface = xlObjectMaterial(xlModelObject(port->id), port->body.triggers[i].trigger.surface.surface);
						break;
					default:
						break;
				}
				switch(port->body.triggers[i].trigger.surface.type)
				{
					case XL_PORT_TRIGGER_SURFACE_ACTION:
						action = xlSurfaceAction(surface);
						if(action == port->body.triggers[i].trigger.surface.trigger.action)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_SURFACE_FRAME:
						frame = xlSurfaceActionFrame(surface);
						if(frame == port->body.triggers[i].trigger.surface.trigger.frame)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_SURFACE_FRAME_LOOP:
						frame = xlSurfaceActionFrame(surface) % xlSurfaceActionFrames(surface, xlSurfaceAction(surface));
						if(frame == port->body.triggers[i].trigger.surface.trigger.frame)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_SURFACE_ACTION_FRAME:
						action = xlSurfaceAction(surface);
						if(action == port->body.triggers[i].trigger.surface.trigger.action)
						{
							frame = xlSurfaceActionFrame(surface);
							if(frame == port->body.triggers[i].trigger.surface.trigger.frame)
								trigger = 1;
						}
						break;
					case XL_PORT_TRIGGER_SURFACE_ACTION_FRAME_LOOP:
						action = xlSurfaceAction(surface);
						if(action == port->body.triggers[i].trigger.surface.trigger.action)
						{
							frame = xlSurfaceActionFrame(surface) % xlSurfaceActionFrames(surface, action);
							if(frame == port->body.triggers[i].trigger.surface.trigger.frame)
								trigger = 1;
						}
						break;
					default:
						break;
				}
				break;
			case XL_PORT_TRIGGER_MODEL:
				switch(port->body.triggers[i].trigger.model.type)
				{
					case XL_PORT_TRIGGER_MODEL_ACTION:
						action = xlModelAction(port->id);
						if(action == port->body.triggers[i].trigger.model.trigger.action)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_MODEL_FRAME:
						frame = xlModelActionFrame(port->id);
						if(frame == port->body.triggers[i].trigger.model.trigger.frame)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_MODEL_FRAME_LOOP:
						frame = xlModelActionFrame(port->id) % xlModelActionFrames(port->id, xlModelAction(port->id));
						if(frame == port->body.triggers[i].trigger.model.trigger.frame)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_MODEL_ACTION_FRAME:
						action = xlModelAction(port->id);
						if(action == port->body.triggers[i].trigger.model.trigger.action)
						{
							frame = xlModelActionFrame(port->id);
							if(frame == port->body.triggers[i].trigger.model.trigger.frame)
								trigger = 1;
						}
						break;
					case XL_PORT_TRIGGER_MODEL_ACTION_FRAME_LOOP:
						action = xlModelAction(port->id);
						if(action == port->body.triggers[i].trigger.model.trigger.action)
						{
							frame = xlModelActionFrame(port->id) % xlModelActionFrames(port->id, action);
							if(frame == port->body.triggers[i].trigger.model.trigger.frame)
								trigger = 1;
						}
						break;
					default:
						break;
				}
				break;
			case XL_PORT_TRIGGER_CAMERA:
				switch(port->type)
				{
					case XL_PORT_CAMERA:
						camera = port->id;
						break;
					case XL_PORT_OPERATOR:
						camera = xlOperatorCamera(port->id);
						break;
					default:
						break;
				}
				switch(port->body.triggers[i].trigger.camera.type)
				{
					case XL_PORT_TRIGGER_CAMERA_PROPERTY:
						property = xlCameraProperty(camera);
						if(property == port->body.triggers[i].trigger.camera.trigger.property)
							trigger = 1;
						break;
					default:
						break;
				}
				break;
			case XL_PORT_TRIGGER_OPERATOR:
				switch(port->body.triggers[i].trigger.operator.type)
				{
					case XL_PORT_TRIGGER_OPERATOR_ACTION:
						action = xlOperatorAction(port->id);
						if(action == port->body.triggers[i].trigger.operator.trigger.action)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_OPERATOR_FRAME:
						frame = xlOperatorActionFrame(port->id);
						if(frame == port->body.triggers[i].trigger.operator.trigger.frame)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_OPERATOR_FRAME_LOOP:
						frame = xlOperatorActionFrame(port->id) % xlOperatorActionFrames(port->id, xlOperatorAction(port->id));
						if(frame == port->body.triggers[i].trigger.operator.trigger.frame)
							trigger = 1;
						break;
					case XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME:
						action = xlOperatorAction(port->id);
						if(action == port->body.triggers[i].trigger.operator.trigger.action)
						{
							frame = xlOperatorActionFrame(port->id);
							if(frame == port->body.triggers[i].trigger.operator.trigger.frame)
								trigger = 1;
						}
						break;
					case XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME_LOOP:
						action = xlOperatorAction(port->id);
						if(action == port->body.triggers[i].trigger.operator.trigger.action)
						{
							frame = xlOperatorActionFrame(port->id) % xlOperatorActionFrames(port->id, action);
							if(frame == port->body.triggers[i].trigger.operator.trigger.frame)
								trigger = 1;
						}
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
	return trigger;
}

XLuint
xlPortTriggerIdUnit(XLuint id, XLuint unit)
{
	XLport *port;

	port = store[id];

	return _xlPortTriggerIdUnit(port, unit);
}

static
XLuint
_xlPortTriggerKeyboardUnit(XLport *port, XLuint unit)
{
	XLuint i;
	XLuint trigger;

	trigger = 0;
	for(i = port->body.units[unit].triggersstart; i < port->body.units[unit].triggersstart + port->body.units[unit].triggers; i++)
	{ 
		switch(port->body.triggers[i].type)
		{
			case XL_PORT_TRIGGER_KEYBOARD:
				if(port->key == port->body.triggers[i].trigger.keyboard.key)
					trigger = 1;
				break;
			default:
				break;
		}
	}
	return trigger;
}

XLuint
xlPortTriggerKeyboardUnit(XLuint id, XLuint unit)
{
	XLport *port;

	port = store[id];

	return _xlPortTriggerKeyboardUnit(port, unit);
}

void
xlPortPerformKeyboard(XLuint id)
{
	XLport *port;
	XLuint i;

	port = store[id];

	for(i = 0; i < port->header.units; i++)
		if(_xlPortTriggerKeyboardUnit(port, i))
			_xlPortActionUnit(port, i);
}

void
xlPortPerformId(XLuint id)
{
	XLport *port;
	XLuint i;

	port = store[id];

	for(i = 0; i < port->header.units; i++)
		if(_xlPortTriggerIdUnit(port, i))
			_xlPortActionUnit(port, i);
}

void
xlPortPerform(XLuint id)
{
	XLport *port;
	XLuint i;

	port = store[id];

	for(i = 0; i < port->header.units; i++)
		if(_xlPortTriggerKeyboardUnit(port, i) || _xlPortTriggerIdUnit(port, i))
			_xlPortActionUnit(port, i);
}
#endif
