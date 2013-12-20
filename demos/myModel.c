#include "myModel.h"

void
myModel(XLenum mode, const XLpath xlpath, XLint t)
{
	XLmodel model;
	XLmetaheader *metaheader;
	XLmetadata *metadata;

	xlMemoryZero(&model, sizeof(XLmodel));

	metaheader = &model.header.metaheader;
	metadata = &model.header.metadata;

	xlMetaHeaderSet(metaheader, XL_MODEL_METAHEADER_MAGIC, xlpath);
	if(mode == XL_DATA_META || mode == XL_DATA_METAHEADER)
	{
		xlMetHeadType(metaheader);
		if(mode == XL_DATA_METAHEADER)
			return;
	}

	switch(t)
	{
		case 0: xlStringCopy(metadata->name, L"Demo"); break;
		default: xlSetError(XL_ERROR_VALUE_INVALID_PARAM); break;
	}
	xlStringCopy(metadata->version, xlGetString(XL_VERSION));
	xlStringCopy(metadata->author, xlGetString(XL_AUTHOR));
	xlStringCopy(metadata->date, xlGetString(XL_DATE));
	xlStringCopy(metadata->copyright, xlGetString(XL_COPYRIGHT));
	xlStringCopy(metadata->license, xlGetString(XL_LICENSE));
	xlStringCopy(metadata->url, xlGetString(XL_URL));
	xlStringCopy(metadata->email, xlGetString(XL_EMAIL));
	xlStringCopy(metadata->tool, xlGetString(XL_TOOL));
	xlStringCopy(metadata->comment, L"Proceduralized");
	xlStringCopy(metadata->xl, xlGetString(XL_VERSION));
	if(mode == XL_DATA_META || mode == XL_DATA_METADATA)
	{
		xlMetDatType(metadata);
		if(mode == XL_DATA_METADATA)
			return;
	}

	if(mode == XL_DATA_META)
		return;

	switch(t)
	{
		case 0:
		{
			XLuint i;

			model.header.bones = 1;
			model.header.parents = 0;
			model.header.vertices = 8;
			model.header.tags = 0;
			model.header.weights = 1;
			model.header.frames = 100;
			model.header.actions = 1;

			model.body.object = xlAlloc(1 * sizeof(XLModelObject));
			xlPathZero(model.body.object->path);
			xlPathCopy(model.body.object->path, "Cube.xlc");

			model.body.bones = xlAlloc(model.header.bones * sizeof(XLModelBone));
			xlStringZero(model.body.bones[0].name);
			xlStringCopy(model.body.bones[0].name, L"Bone");
			xlRangeLoad(&model.body.bones[0].parents, 0, 0);

			model.body.vertices = xlAlloc(model.header.vertices * sizeof(XLModelVertex));
			for(i = 0; i < model.header.vertices; i++)
			{
				xlRangeLoad(&model.body.vertices[i].weights, 0, 1);
			}
			
			model.body.weights = xlAlloc(model.header.weights * sizeof(XLModelWeight));
			model.body.weights[0].bone = 0;
			model.body.weights[0].value = XL_REAL(1);

			model.body.frames = xlAlloc(model.header.frames * sizeof(XLModelFrame));
			XLmatrix matrix;
			XLvector vector;
			xlMatrixAssignIdentity(&matrix);
			xlVectorAssignReals(&vector, XL_REAL(0.95), XL_REAL(0.95), XL_REAL(0.95));
			model.body.frames[0].bones = xlAlloc(model.header.bones * sizeof(XLModelBoneFrame));
			xlMatrixAssignIdentity(&model.body.frames[0].bones[0].matrix);
			xlMatrixAssignIdentity(&model.body.frames[0].matrix);
			model.body.frames[0].time = XL_REAL(1);
			for(i = 1; i < model.header.frames / 2; i++)
			{
				model.body.frames[i].bones = xlAlloc(model.header.bones * sizeof(XLModelBoneFrame));
				xlMatrixAssignCopy(&model.body.frames[i].bones[0].matrix, &matrix);
				xlMatrixAssignIdentity(&model.body.frames[i].matrix);
				model.body.frames[i].time = XL_REAL(1) / model.header.frames;
				xlMatrixScale(&matrix, &vector);
			}
			xlVectorAssignReals(&vector, XL_REAL(1.05), XL_REAL(1.05), XL_REAL(1.05));
			model.body.frames[i].bones = xlAlloc(model.header.bones * sizeof(XLModelBoneFrame));
			xlMatrixAssignCopy(&model.body.frames[i].bones[0].matrix, &matrix);
			xlMatrixAssignIdentity(&model.body.frames[i].matrix);
			model.body.frames[i].time = XL_REAL(1);
			for(i = model.header.frames / 2 + 1; i < model.header.frames; i++)
			{
				model.body.frames[i].bones = xlAlloc(model.header.bones * sizeof(XLModelBoneFrame));
				xlMatrixAssignCopy(&model.body.frames[i].bones[0].matrix, &matrix);
				xlMatrixAssignIdentity(&model.body.frames[i].matrix);
				model.body.frames[i].time = XL_REAL(1) / model.header.frames;
				xlMatrixScale(&matrix, &vector);
			}

			model.body.actions = xlAlloc(model.header.actions * sizeof(XLModelAction));
			xlStringZero(model.body.actions[0].name);
			xlStringCopy(model.body.actions[0].name, L"sy");
			xlRangeLoad(&model.body.actions[0].frames, 0, model.header.frames);

			model.runtime.morphfactor = XL_REAL(1);
			break;
		}
		default:
			xlSetError(XL_ERROR_VALUE_INVALID_PARAM);
			break;
	}

	xlModType(&model);
}

XLuint
myModCubeXL(XLenum mode, const XLpath xlpath)
{
	myModel(mode, xlpath, 0);

	return 0;
}
