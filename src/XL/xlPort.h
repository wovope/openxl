#ifndef XL_PORT_H
#define XL_PORT_H

#include <XL/xlTypes.h>

#include <XL/id.h>

typedef struct
{
	XLint magic;
	XLuint triggers;
	XLuint actions;
	XLuint units;
} XLPortHeader;

typedef struct
{
	enum
	{
		XL_PORT_TRIGGER_NONE = 0,
		XL_PORT_TRIGGER_KEYBOARD,
		XL_PORT_TRIGGER_MOUSE,
		XL_PORT_TRIGGER_GAMEPAD,
		XL_PORT_TRIGGER_MATERIAL,
		XL_PORT_TRIGGER_SURFACE,
		XL_PORT_TRIGGER_MODEL,
		XL_PORT_TRIGGER_CAMERA,
		XL_PORT_TRIGGER_OPERATOR
	} type;
	union
	{
		struct
		{
			XLwchar key;
		} keyboard;
		struct
		{
			XLuint material;
			enum
			{
				XL_PORT_TRIGGER_MATERIAL_NONE = 0,
				XL_PORT_TRIGGER_MATERIAL_PROPERTY
			} type;
			struct
			{
				XLuint property;
			} trigger;
		} material;
		struct
		{
			XLuint surface;
			enum
			{
				XL_PORT_TRIGGER_SURFACE_NONE = 0,
				XL_PORT_TRIGGER_SURFACE_ACTION,
				XL_PORT_TRIGGER_SURFACE_FRAME,
				XL_PORT_TRIGGER_SURFACE_FRAME_LOOP,
				XL_PORT_TRIGGER_SURFACE_ACTION_FRAME,
				XL_PORT_TRIGGER_SURFACE_ACTION_FRAME_LOOP
			} type;
			struct
			{
				XLuint action, frame;
			} trigger;
		} surface;
		struct
		{
			enum
			{
				XL_PORT_TRIGGER_MODEL_NONE = 0,
				XL_PORT_TRIGGER_MODEL_ACTION,
				XL_PORT_TRIGGER_MODEL_FRAME,
				XL_PORT_TRIGGER_MODEL_FRAME_LOOP,
				XL_PORT_TRIGGER_MODEL_ACTION_FRAME,
				XL_PORT_TRIGGER_MODEL_ACTION_FRAME_LOOP
			} type;
			struct
			{
				XLuint action, frame;
			} trigger;
		} model;
		struct
		{
			XLuint camera;
			enum
			{
				XL_PORT_TRIGGER_CAMERA_NONE = 0,
				XL_PORT_TRIGGER_CAMERA_PROPERTY,
			} type;
			struct
			{
				XLuint property;
			} trigger;
		} camera;
		struct
		{
			enum
			{
				XL_PORT_TRIGGER_OPERATOR_NONE = 0,
				XL_PORT_TRIGGER_OPERATOR_ACTION,
				XL_PORT_TRIGGER_OPERATOR_FRAME,
				XL_PORT_TRIGGER_OPERATOR_FRAME_LOOP,
				XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME,
				XL_PORT_TRIGGER_OPERATOR_ACTION_FRAME_LOOP
			} type;
			struct
			{
				XLuint action, frame;
			} trigger;
		} operator;
	} trigger;
} XLPortTrigger;

typedef struct
{
	enum
	{
		XL_PORT_ACTION_NONE = 0,
		XL_PORT_ACTION_MATERIAL,
		XL_PORT_ACTION_SURFACE,
		XL_PORT_ACTION_OBJECT,
		XL_PORT_ACTION_MODEL,
		XL_PORT_ACTION_CAMERA,
		XL_PORT_ACTION_OPERATOR
	} type;
	union
	{
		struct
		{
			XLuint material;
			enum
			{
				XL_PORT_ACTION_MATERIAL_NONE = 0,
				XL_PORT_ACTION_MATERIAL_PROPERTY,
				XL_PORT_ACTION_MATERIAL_MATRIX
			} type;
			struct
			{
				XLuint property;
				float matrix[16];
			} action;
		} material;
		struct
		{
			XLuint surface;
			enum
			{
				XL_PORT_ACTION_SURFACE_NONE = 0,
				XL_PORT_ACTION_SURFACE_ACTION,
				XL_PORT_ACTION_SURFACE_FRAME,
				XL_PORT_ACTION_SURFACE_FRAME_LOOP,
				XL_PORT_ACTION_SURFACE_ACTION_FRAME,
				XL_PORT_ACTION_SURFACE_ACTION_FRAME_LOOP
			} type;
			struct
			{
				XLuint action, frame;
			} action;
		} surface;
		struct
		{
			enum
			{
				XL_PORT_ACTION_OBJECT_NONE = 0,
				XL_PORT_ACTION_OBJECT_MATRIX
			} type;
			struct
			{
				float matrix[16];
			} action;
		} object;
		struct
		{
			enum
			{
				XL_PORT_ACTION_MODEL_NONE = 0,
				XL_PORT_ACTION_MODEL_ACTION,
				XL_PORT_ACTION_MODEL_FRAME,
				XL_PORT_ACTION_MODEL_ACTION_FRAME
			} type;
			struct
			{
				XLuint action, frame;
			} action;
		} model;
		struct
		{
			enum
			{
				XL_PORT_ACTION_CAMERA_NONE = 0,
				XL_PORT_ACTION_CAMERA_PROPERTY,
				XL_PORT_ACTION_CAMERA_MATRIX
			} type;
			struct
			{
				XLuint property;
				float matrix[16];
			} action;
		} camera;
		struct
		{
			enum
			{
				XL_PORT_ACTION_OPERATOR_NONE = 0,
				XL_PORT_ACTION_OPERATOR_ACTION,
				XL_PORT_ACTION_OPERATOR_FRAME,
				XL_PORT_ACTION_OPERATOR_FRAME_LOOP,
				XL_PORT_ACTION_OPERATOR_ACTION_FRAME,
				XL_PORT_ACTION_OPERATOR_ACTION_FRAME_LOOP
			} type;
			struct
			{
				XLuint action, frame;
			} action;
		} operator;
	} action;
} XLPortAction;

typedef struct
{
	XLstring name;
	XLuint triggersstart, triggers;
	XLuint actionsstart, actions;
} XLPortUnit;

typedef struct
{
	XLPortTrigger *triggers;
	XLPortAction *actions;
	XLPortUnit *units;
} XLPortBody;

typedef struct
{
	XLPortHeader header;
	XLPortBody body;

	enum
	{
		XL_PORT_NONE = 0,
		XL_PORT_MATERIAL,
		XL_PORT_SURFACE,
		XL_PORT_OBJECT,
		XL_PORT_MODEL,
		XL_PORT_CAMERA,
		XL_PORT_OPERATOR
	} type;
	XLid id;
	XLwchar key;
} XLport;

idDeclareAPI(xl, Port);

idStoreDecl(xl, XL, port, Port);

idTypeDecl(xl, XL, port, Prt);

void
xlPortLoad(XLid id, const char *filepath);

idUnloadDecl(xl, Port);

void
xlPortCompile(XLid id, const char *filepath);

void
xlPortDecompile(XLid id, const char *filepath);

void
xlPortSave(XLid id, const char *filepath);

XLuint
xlPortTriggers(XLid id);

XLuint
xlPortActions(XLid id);

XLuint
xlPortUnits(XLid id);

XLuint
xlPortTriggerType(XLid id, XLuint trigger);

XLuint
xlPortActionType(XLid id, XLuint action);

XLuint
xlPortUnitId(XLid id, const XLwchar *name);

const XLwchar *
xlPortUnitName(XLid id, XLuint unit);

void
xlPortSetId(XLid id, XLuint type, XLuint object);

void
xlPortSetMaterial(XLid id, XLuint material);

void
xlPortSetSurface(XLid id, XLuint surface);

void
xlPortSetObject(XLid id, XLuint object);

void
xlPortSetModel(XLid id, XLuint model);

void
xlPortSetCamera(XLid id, XLuint camera);

void
xlPortSetOperator(XLid id, XLuint operator);

void
xlPortSetKeyboard(XLid id, XLwchar key);

XLuint
xlPortIdType(XLid id);

XLuint
xlPortId(XLid id);

XLuint
xlPortTriggerIdUnit(XLid id, XLuint unit);

XLuint
xlPortTriggerKeyboardUnit(XLid id, XLuint unit);

void
xlPortActionUnit(XLid id, XLuint unit);

void
xlPortPerformKeyboard(XLid id);

void
xlPortPerformId(XLid id);

void
xlPortPerform(XLid id);

#include <XL/unid.h>

#endif
