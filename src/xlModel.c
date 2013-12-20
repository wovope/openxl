#include "XL/xlModel.h"
#include "XL/xl.h"

XLuint
xlGetModBoneId(const XLstring name)
{
	XLmodel *bind = xlGetModel();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.bones[i].name, name); i++);

	return i;
}

const XLwchar *
xlGetModBoneName(XLuint bone)
{
	XLmodel *bind = xlGetModel();

	return bind->body.bones[bone].name;
}

XLuint
xlGetModBoneParents(XLuint bone)
{
	XLmodel *bind = xlGetModel();

	return bind->body.bones[bone].parents.count;
}

void
xlGetModTagMatrix(XLuint tag, XLmatrix *matrix)
{
	XLmodel *bind = xlGetModel();
	XLobject *object = xlGetObject();
	XLModelTag *tags;
	XLModelWeight *weights;
	XLModelFrame *frames;
	XLModelAction *actions;
	XLmatrix tmp, m1, m2;
	XLuint i;

	tags = bind->body.tags;
	weights = bind->body.weights;
	frames = bind->body.frames;
	actions = bind->body.actions;

	xlMatrixAssignZero(&tmp);
	for(i = tags[tag].weights.start; i < tags[tag].weights.start + tags[tag].weights.count; i++)
	{
		if(bind->runtime.morph)
		{
			xlMatrixAssignMultReal(matrix, &frames[actions[bind->runtime.action[0]].frames.start + bind->runtime.frame[0] % actions[bind->runtime.action[0]].frames.count].bones[weights[i].bone].matrix, weights[i].value * (XL_REAL(1) - bind->runtime.morphfactor));
			xlMatrixAdd(&tmp, matrix);
			xlMatrixAssignMultReal(matrix, &frames[actions[bind->runtime.action[1]].frames.start + bind->runtime.frame[1] % actions[bind->runtime.action[1]].frames.count].bones[weights[i].bone].matrix, weights[i].value * bind->runtime.morphfactor);
			xlMatrixAdd(&tmp, matrix);
		}
		else if(bind->runtime.blend)
		{
			xlMatrixAssignMultReal(&m1, &frames[actions[bind->runtime.action[0]].frames.start + bind->runtime.frame[0] % actions[bind->runtime.action[0]].frames.count].bones[weights[i].bone].matrix, weights[i].value);
			xlMatrixAssignMultReal(&m2, &frames[actions[bind->runtime.action[1]].frames.start + bind->runtime.frame[1] % actions[bind->runtime.action[1]].frames.count].bones[weights[i].bone].matrix, weights[i].value);
			xlMatrixAssignMult(matrix, &m1, &m2);
			xlMatrixAdd(&tmp, matrix);
		}
		else
		{
			xlMatrixAssignMultReal(matrix, &frames[actions[bind->runtime.action[1]].frames.start + bind->runtime.frame[1] % actions[bind->runtime.action[1]].frames.count].bones[weights[i].bone].matrix, weights[i].value);
			xlMatrixAdd(&tmp, matrix);
		}
	}
	xlMatrixAssignMult(matrix, &tmp, &object->body.tags[tag].matrix);
}

XLuint
xlGetModActionId(const XLstring name)
{
	XLmodel *bind = xlGetModel();
	XLuint i;

	for(i = 0; !xlStringEqual(bind->body.actions[i].name, name); i++);

	return i;
}

const XLwchar *
xlGetModActionName(XLuint action)
{
	XLmodel *bind = xlGetModel();

	return bind->body.actions[action].name;
}

XLuint
xlGetModActionFrames(XLuint action)
{
	XLmodel *bind = xlGetModel();

	return bind->body.actions[action].frames.count;
}

const XLmatrix *
xlGetModActionFrameMatrix(XLuint action, XLuint frame)
{
	XLmodel *bind = xlGetModel();

	return &bind->body.frames[bind->body.actions[action].frames.start + frame].matrix;
}

XLreal
xlGetModActionFrameTime(XLuint action, XLuint frame)
{
	XLmodel *bind = xlGetModel();

	return bind->body.frames[bind->body.actions[action].frames.start + frame].time;
}

XLuint
xlGetModAction(void)
{
	XLmodel *bind = xlGetModel();

	return bind->runtime.action[1];
}

XLuint
xlGetModActionFrame(void)
{
	XLmodel *bind = xlGetModel();

	return bind->runtime.frame[1];
}

void
xlModAction(XLuint action)
{
	XLmodel *bind = xlGetModel();

	bind->runtime.action[0] = bind->runtime.action[1];
	bind->runtime.frame[0] = bind->runtime.frame[1];
	bind->runtime.action[1] = action;
	bind->runtime.frame[1] = 0;
	bind->runtime.morphfactor = XL_REAL(0);
	bind->runtime.time[0] = bind->runtime.time[1];
	bind->runtime.time[1] = XL_REAL(0);
}

void
xlModActionMorph(XLboolean morph)
{
	XLmodel *bind = xlGetModel();

	bind->runtime.morph = morph;
}

void
xlModActionBlend(XLboolean blend)
{
	XLmodel *bind = xlGetModel();

	bind->runtime.blend = blend;
}

void
xlModActionFrame(XLuint frame)
{
	XLmodel *bind = xlGetModel();

	bind->runtime.action[0] = bind->runtime.action[1];
	bind->runtime.frame[0] = bind->runtime.frame[1];
	bind->runtime.frame[1] = frame;
	bind->runtime.morphfactor = XL_REAL(0);
	bind->runtime.time[0] = bind->runtime.time[1];
	bind->runtime.time[1] = XL_REAL(0);
}

void
xlModObject(void)
{
	XLmodel *bind = xlGetModel();

	xlBindObject(bind->runtime.object);
}

void
xlModAnim(void)
{
	XLmodel *bind = xlGetModel();
	XLobject *object;
	XLModelVertex *vertices;
	XLModelWeight *weights;
	XLModelFrame *frames;
	XLModelAction *actions;
	XLmatrix matrix, m1, m2;
	XLpoint tmp, tmp2;
	XLuint i, j;

	xlModObject();
	object = xlGetObject();

	vertices = bind->body.vertices;
	weights = bind->body.weights;
	frames = bind->body.frames;
	actions = bind->body.actions;

	for(i = 0; i < bind->header.vertices; i++)
	{
		xlPointAssignZero(&bind->runtime.anim[0][i]);
		xlPointAssignZero(&bind->runtime.anim[1][i]);
		xlMatrixAssignZero(&m1);
		xlMatrixAssignZero(&m2);
		for(j = vertices[i].weights.start; j < vertices[i].weights.start + vertices[i].weights.count; j++)
		{
			xlMatrixAssignMultReal(&matrix, &frames[actions[bind->runtime.action[0]].frames.start + bind->runtime.frame[0] % actions[bind->runtime.action[0]].frames.count].bones[weights[j].bone].matrix, weights[j].value);
			xlMatrixAdd(&m1, &matrix);
			xlMatrixAssignMultReal(&matrix, &frames[actions[bind->runtime.action[1]].frames.start + bind->runtime.frame[1] % actions[bind->runtime.action[1]].frames.count].bones[weights[j].bone].matrix, weights[j].value);
			xlMatrixAdd(&m2, &matrix);
		}
		if(bind->runtime.morph)
		{
			xlPointAssignMultMatrix(&bind->runtime.anim[0][i], &object->body.vertices[i].coord, &m1);
			xlPointAssignMultMatrix(&bind->runtime.anim[1][i], &object->body.vertices[i].coord, &m2);
			xlPointAssignMultReal(&tmp, &bind->runtime.anim[0][i], XL_REAL(1) - bind->runtime.morphfactor);
			xlPointAssignMultReal(&tmp2, &bind->runtime.anim[1][i], bind->runtime.morphfactor);
			xlPointAssignAdd(&bind->runtime.anim[2][i], &tmp, &tmp2);
		}
		else if(bind->runtime.blend)
		{
			xlMatrixAssignMult(&matrix, &m1, &m2);
			xlPointAssignMultMatrix(&bind->runtime.anim[2][i], &object->body.vertices[i].coord, &matrix);
		}
		else
		{
			xlPointAssignMultMatrix(&bind->runtime.anim[2][i], &object->body.vertices[i].coord, &m2);
		}
	}
}

void
xlModObjectVertices(void)
{
	XLmodel *bind = xlGetModel();

	xlObjVerticesCoords(bind->runtime.anim[2]);
}
