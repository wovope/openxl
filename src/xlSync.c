#include "XL/xlType.h"
#include "XL/xl.h"

void
xlTimeSync(XLreal delta)
{
	xlTimeTotal += delta;
	xlTimeDelta = delta;
}

void
xlSurfSync(void)
{
	XLsurface *surface = xlGetSurface();
	XLSurfaceFrame *frames;
	XLSurfaceAction *actions;

	frames = surface->body.frames;
	actions = surface->body.actions;

	for(surface->runtime.time += xlTimeDelta; surface->runtime.time >= frames[actions[surface->runtime.action].frames.start + surface->runtime.frame % actions[surface->runtime.action].frames.count].time; surface->runtime.time -= frames[actions[surface->runtime.action].frames.start + surface->runtime.frame % actions[surface->runtime.action].frames.count].time, surface->runtime.frame++);
}

void
xlObjSync(void)
{
	XLobject *object = xlGetObject();
	XLObjectMaterial *materials;
	XLuint i;

	materials = object->body.materials;
	for(i = 0; i < object->header.materials; i++)
		if(materials[i].surface)
		{
			xlBindSurface(object->runtime.materials[i]);
			xlSurfSync();
		}
}

void
xlModObjectSync(void)
{
	XLmodel *model = xlGetModel();

	xlBindObject(model->runtime.object);
	xlObjSync();
}

void
xlModSync(void)
{
	XLmodel *model = xlGetModel();
	XLobject *object = xlGetObject();
	XLModelFrame *frames;
	XLModelAction *actions;
	XLmatrix matrix, matrix2;

	frames = model->body.frames;
	actions = model->body.actions;

	xlBindObject(model->runtime.object);
	xlObjSync();

	if(model->runtime.morph)
	{
		if(model->runtime.morphfactor == XL_REAL(1))
		{
			for(model->runtime.time[1] += xlTimeDelta; model->runtime.time[1] >= frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time; model->runtime.time[1] -= frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time, model->runtime.frame[1]++)
				xlMatrixMult(&object->runtime.matrix, &frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].matrix);
		}
		else
		{
			model->runtime.morphfactor += xlTimeDelta / (frames[actions[model->runtime.action[0]].frames.start + model->runtime.frame[0] % actions[model->runtime.action[0]].frames.count].time * (XL_REAL(1) - model->runtime.morphfactor) + frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time * model->runtime.morphfactor) / XL_REAL(10);
			if(model->runtime.morphfactor > XL_REAL(1)) model->runtime.morphfactor = XL_REAL(1);
			xlMatrixAssignMultReal(&matrix, &frames[actions[model->runtime.action[0]].frames.start + model->runtime.frame[0] % actions[model->runtime.action[0]].frames.count].matrix, XL_REAL(1) - model->runtime.morphfactor);
			xlMatrixAssignMultReal(&matrix2, &frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].matrix, model->runtime.morphfactor);
			xlMatrixAdd(&matrix, &matrix2);
			xlMatrixMult(&object->runtime.matrix, &matrix);
		}
	}
	else if(model->runtime.blend)
	{
		for(model->runtime.time[0] += xlTimeDelta; model->runtime.time[0] >= frames[actions[model->runtime.action[0]].frames.start + model->runtime.frame[0] % actions[model->runtime.action[0]].frames.count].time; model->runtime.time[0] -= frames[actions[model->runtime.action[0]].frames.start + model->runtime.frame[0] % actions[model->runtime.action[0]].frames.count].time, model->runtime.frame[0]++)
			xlMatrixMult(&object->runtime.matrix, &frames[actions[model->runtime.action[0]].frames.start + model->runtime.frame[0] % actions[model->runtime.action[0]].frames.count].matrix);
		for(model->runtime.time[1] += xlTimeDelta; model->runtime.time[1] >= frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time; model->runtime.time[1] -= frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time, model->runtime.frame[1]++)
			xlMatrixMult(&object->runtime.matrix, &frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].matrix);
	}
	else
	{
		for(model->runtime.time[1] += xlTimeDelta; model->runtime.time[1] >= frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time; model->runtime.time[1] -= frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].time, model->runtime.frame[1]++) 
			xlMatrixMult(&object->runtime.matrix, &frames[actions[model->runtime.action[1]].frames.start + model->runtime.frame[1] % actions[model->runtime.action[1]].frames.count].matrix);
	}

	xlModAnim();
}

void
xlOpSync(void)
{
	XLoperator *operator = xlGetOperator();
	XLOperatorFrame *frames;
	XLOperatorAction *actions;

	frames = operator->body.frames;
	actions = operator->body.actions;

	for(operator->runtime.time += xlTimeDelta; operator->runtime.time >= frames[actions[operator->runtime.action].frames.start + operator->runtime.frame % actions[operator->runtime.action].frames.count].time; operator->runtime.time -= frames[actions[operator->runtime.action].frames.start + operator->runtime.frame % actions[operator->runtime.action].frames.count].time, operator->runtime.frame++);
}
