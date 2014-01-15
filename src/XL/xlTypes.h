#ifndef XL_TYPES_H
#define XL_TYPES_H

#include <XL/xlMacros.h>

#define XLsize size_t
#define XLsizei XLsize

#define XLtime time_t
#define XLclock clock_t

#define XLvoid void

#define XLbyte char
#define XLubyte unsigned XLbyte

#define XLwchar wchar_t
#define XLchar char

#define XLint int
#define XLuint unsigned XLint
#define XLuint8 uint8_t
#define XLuint16 uint16_t
#define XLuint32 uint32_t
#define XLint64 int64_t
#define XLlong long XLint
#define XLulong unsigned XLlong

#define XLboolean XLuint

#define XLid XLuint

#define XLfloat float
#define XLdouble double

#if defined(XL_REAL_TYPE_FLOAT)
	typedef XLfloat XLreal;
#elif defined(XL_REAL_TYPE_DOUBLE)
	typedef XLdouble XLreal;
#endif

#ifdef XL_SIMD
	typedef XLreal XL_SIMD_VECTOR_SIZE(XLsimd4sr, 4 * sizeof(XLreal));
	
	typedef XLreal XL_SIMD_VECTOR_SIZE(XLsimd16sr, 16 * sizeof(XLreal));
	
	#if defined(XL_REAL_TYPE_FLOAT)
		typedef XLint XL_SIMD_VECTOR_SIZE(XLsimd4si, 4 * sizeof(XLint));
	
		typedef XLint XL_SIMD_VECTOR_SIZE(XLsimd16si, 16 * sizeof(XLint));
	#elif defined(XL_REAL_TYPE_DOUBLE)
		typedef XLint64 XL_SIMD_VECTOR_SIZE(XLsimd4si, 4 * sizeof(XLint64));
	
		typedef XLint64 XL_SIMD_VECTOR_SIZE(XLsimd16si, 16 * sizeof(XLint64));
	#endif

	typedef struct _XLpair XL_SIMD_ALIGNED_4SR(XLpair);
	typedef struct _XLcolor XL_SIMD_ALIGNED_4SR(XLcolor);
	typedef struct _XLpoint XL_SIMD_ALIGNED_4SR(XLpoint);
	typedef struct _XLvector XL_SIMD_ALIGNED_4SR(XLvector);
	typedef struct _XLmatrix XL_SIMD_ALIGNED_16SR(XLmatrix);
#else
	typedef struct _XLpair XLpair;
	typedef struct _XLcolor XLcolor;
	typedef struct _XLpoint XLpoint;
	typedef struct _XLvector XLvector;
	typedef struct _XLmatrix XLmatrix;
#endif

typedef XLwchar XLstring[XL_STRING_SIZE];
typedef XLwchar XLstringbuffer[XL_STRING_BUFFER_SIZE];

typedef XLchar XLpath[XL_PATH_SIZE];
typedef XLchar XLpathbuffer[XL_PATH_BUFFER_SIZE];

/*
typedef struct
{
	FILE *plain;
	BZFILE *bzip2;
	XLenum type;
} XLfile;
*/
#define XLfile FILE

typedef enum _XLenum XLenum;

typedef struct _XLmetaheader XLmetaheader;
typedef struct _XLmetadata XLmetadata;
typedef struct _XLrange XLrange;
typedef struct _XLImageHeader XLImageHeader;
typedef struct _XLImageBody XLImageBody;
typedef struct _XLImageRuntime XLImageRuntime;
typedef struct _XLimage XLimage;
typedef struct _XLSoundHeader XLSoundHeader;
typedef struct _XLSoundBody XLSoundBody;
typedef struct _XLSoundRuntime XLSoundRuntime;
typedef struct _XLsound XLsound;
typedef struct _XLFontHeader XLFontHeader;
typedef struct _XLFontProperty XLFontProperty;
typedef struct _XLFontBody XLFontBody;
typedef struct _XLFontRuntime XLFontRuntime;
typedef struct _XLfont XLfont;
typedef struct _XLMaterialHeader XLMaterialHeader;
typedef struct _XLMaterialProperty XLMaterialProperty;
typedef struct _XLMaterialBody XLMaterialBody;
typedef struct _XLMaterialRuntime XLMaterialRuntime;
typedef struct _XLmaterial XLmaterial;
typedef struct _XLSurfaceHeader XLSurfaceHeader;
typedef struct _XLSurfaceMaterial XLSurfaceMaterial;
typedef struct _XLSurfaceFrame XLSurfaceFrame;
typedef struct _XLSurfaceAction XLSurfaceAction;
typedef struct _XLSurfaceBody XLSurfaceBody;
typedef struct _XLSurfaceRuntime XLSurfaceRuntime;
typedef struct _XLsurface XLsurface;
typedef struct _XLvertex XLvertex;
typedef struct _XLObjectHeader XLObjectHeader;
typedef struct _XLObjectVertex XLObjectVertex;
typedef struct _XLObjectMaterial XLObjectMaterial;
typedef struct _XLObjectFace XLObjectFace;
typedef struct _XLObjectTag XLObjectTag;
typedef struct _XLObjectBound XLObjectBound;
typedef struct _XLObjectBody XLObjectBody;
typedef struct _XLObjectRuntime XLObjectRuntime;
typedef struct _XLobject XLobject;
typedef struct _XLModelHeader XLModelHeader;
typedef struct _XLModelObject XLModelObject;
typedef struct _XLModelBone XLModelBone;
typedef struct _XLModelParent XLModelParent;
typedef struct _XLModelVertex XLModelVertex;
typedef struct _XLModelWeight XLModelWeight;
typedef struct _XLModelTag XLModelTag;
typedef struct _XLModelBoneFrame XLModelBoneFrame;
typedef struct _XLModelFrame XLModelFrame;
typedef struct _XLModelAction XLModelAction;
typedef struct _XLModelBody XLModelBody;
typedef struct _XLModelRuntime XLModelRuntime;
typedef struct _XLmodel XLmodel;
typedef struct _XLParticlesHeader XLParticlesHeader;
typedef struct _XLParticlesBody XLParticlesBody;
typedef struct _XLParticlesRuntime XLParticlesRuntime;
typedef struct _XLparticle XLparticle;
typedef struct _XLparticles XLparticles;
typedef struct _XLCameraHeader XLCameraHeader;
typedef struct _XLCameraProperty XLCameraProperty;
typedef struct _XLCameraBody XLCameraBody;
typedef struct _XLCameraRuntime XLCameraRuntime;
typedef struct _XLcamera XLcamera;
typedef struct _XLOperatorHeader XLOperatorHeader;
typedef struct _XLOperatorCamera XLOperatorCamera;
typedef struct _XLOperatorFrame XLOperatorFrame;
typedef struct _XLOperatorAction XLOperatorAction;
typedef struct _XLOperatorBody XLOperatorBody;
typedef struct _XLOperatorRuntime XLOperatorRuntime;
typedef struct _XLoperator XLoperator;
typedef struct _XLViewportHeader XLViewportHeader;
typedef struct _XLViewportProperty XLViewportProperty;
typedef struct _XLViewportBody XLViewportBody;
typedef struct _XLViewportRuntime XLViewportRuntime;
typedef struct _XLviewport XLviewport;
typedef struct _XLWindowHeader XLWindowHeader;
typedef struct _XLWindowProperty XLWindowProperty;
typedef struct _XLWindowBody XLWindowBody;
typedef struct _XLWindowRuntime XLWindowRuntime;
typedef struct _XLwindow XLwindow;

typedef struct _XLerror XLerror;

typedef struct _XLstore XLstore;
typedef XLid XLbind;
typedef struct _XLdata XLdata;

#define _xlPairEnum(e, c) \
	XL_PAIR_ ## e,
#define _xlColorEnum(e, c) \
	XL_COLOR_ ## e,
#define _xlPointEnum(e, c) \
	XL_POINT_ ## e,
#define _xlVectorEnum(e, c) \
	XL_VECTOR_ ## e,
#define _xlMatrixEnum(e, c) \
	XL_MATRIX_ ## e,

enum _XLenum
{
	XL_NONE,

	XL_VENDOR,
	XL_RENDERER,
	XL_VERSION,

	XL_NAME,
	XL_DESCRIPTION,
	XL_AUTHOR,
	XL_DATE,
	XL_COPYRIGHT,
	XL_LICENSE,
	XL_URL,
	XL_EMAIL,
	XL_TOOL,

	XL_ERROR_FILE,
	XL_ERROR_FUNCTION,
	XL_ERROR_LINE,
	XL_ERROR_VALUE,
	XL_ERROR_VALUE_NONE,
	XL_ERROR_VALUE_INVALID,
	XL_ERROR_VALUE_INVALID_ENUM,
	XL_ERROR_VALUE_INVALID_VALUE,
	XL_ERROR_VALUE_INVALID_OP,
	XL_ERROR_VALUE_INVALID_PARAM,
	XL_ERROR_VALUE_INVALID_PATH,
	XL_ERROR_VALUE_INVALID_DATA,
	XL_ERROR_VALUE_UNKNOWN,
	
	XL_LOG_LEVEL_NULL,
	XL_LOG_LEVEL_STDOUT,
	XL_LOG_LEVEL_STDERR,

	//XL_TIME,
	//XL_TIME_TICKS,
	XL_TIME_TOTAL,
	XL_TIME_DELTA,

	xlPairsForEach(_xlPairEnum)
	xlColorsForEach(_xlColorEnum)
	xlPointsForEach(_xlPointEnum)
	xlVectorsForEach(_xlVectorEnum)
	xlMatricesForEach(_xlMatrixEnum)

	XL_FILE_PLAIN,
	XL_FILE_BZIP2, 

	XL_DATA_BINARY,
	XL_DATA_SOURCE,
	XL_DATA_PROCESS,
	XL_DATA_EXTERNAL,
	XL_DATA_METAHEADER,
	XL_DATA_METADATA,
	XL_DATA_META,
	XL_DATA_LOAD,

	XL_METAHEADER,
	XL_METAHEADER_PATH,
	XL_METAHEADER_MAGIC,
	XL_METAHEADER_TYPE,

	XL_METADATA,
	XL_METADATA_NAME,
	XL_METADATA_VERSION,
	XL_METADATA_AUTHOR,
	XL_METADATA_DATE,
	XL_METADATA_COPYRIGHT,
	XL_METADATA_LICENSE,
	XL_METADATA_URL,
	XL_METADATA_EMAIL,
	XL_METADATA_TOOL,
	XL_METADATA_COMMENT,
	XL_METADATA_XL,

	XL_IMAGE,
	XL_IMAGE_METAHEADER_PATH,
	XL_IMAGE_METAHEADER_MAGIC,
	XL_IMAGE_METAHEADER_TYPE,
	XL_IMAGE_METADATA_NAME,
	XL_IMAGE_METADATA_VERSION,
	XL_IMAGE_METADATA_AUTHOR,
	XL_IMAGE_METADATA_DATE,
	XL_IMAGE_METADATA_COPYRIGHT,
	XL_IMAGE_METADATA_LICENSE,
	XL_IMAGE_METADATA_URL,
	XL_IMAGE_METADATA_EMAIL,
	XL_IMAGE_METADATA_TOOL,
	XL_IMAGE_METADATA_COMMENT,
	XL_IMAGE_METADATA_XL,
	XL_IMAGE_WIDTH,
	XL_IMAGE_HEIGHT,
	XL_IMAGE_SIZE,
	XL_IMAGE_BYTES_PER_PIXEL,
	XL_IMAGE_PIXELS,
	XL_IMAGE_TEXTURE,

	XL_SOUND,
	XL_SOUND_METAHEADER_PATH,
	XL_SOUND_METAHEADER_MAGIC,
	XL_SOUND_METAHEADER_TYPE,
	XL_SOUND_METADATA_NAME,
	XL_SOUND_METADATA_VERSION,
	XL_SOUND_METADATA_AUTHOR,
	XL_SOUND_METADATA_DATE,
	XL_SOUND_METADATA_COPYRIGHT,
	XL_SOUND_METADATA_LICENSE,
	XL_SOUND_METADATA_URL,
	XL_SOUND_METADATA_EMAIL,
	XL_SOUND_METADATA_TOOL,
	XL_SOUND_METADATA_COMMENT,
	XL_SOUND_METADATA_XL,
	XL_SOUND_FREQUENCY,
	XL_SOUND_LENGTH,
	XL_SOUND_BYTES_PER_SAMPLE,
	XL_SOUND_SAMPLES,
	XL_SOUND_BUFFER,
	XL_SOUND_SOURCE,

	XL_RENDER_TEXTURE,
	XL_RENDER_POINTS,
	XL_RENDER_OUTLINE,
	XL_RENDER_OUTLINES,
	XL_RENDER_FILL,
	XL_RENDER_MODERN,
	XL_RENDER_WIRE,
	XL_RENDER_SOLID,

	XL_FONT,
	XL_FONT_METAHEADER_PATH,
	XL_FONT_METAHEADER_MAGIC,
	XL_FONT_METAHEADER_TYPE,
	XL_FONT_METADATA_NAME,
	XL_FONT_METADATA_VERSION,
	XL_FONT_METADATA_AUTHOR,
	XL_FONT_METADATA_DATE,
	XL_FONT_METADATA_COPYRIGHT,
	XL_FONT_METADATA_LICENSE,
	XL_FONT_METADATA_URL,
	XL_FONT_METADATA_EMAIL,
	XL_FONT_METADATA_TOOL,
	XL_FONT_METADATA_COMMENT,
	XL_FONT_METADATA_XL,
	XL_FONT_PROPERTIES,
	XL_FONT_PROPERTY,
	XL_FONT_PROPERTY_NAME,
	XL_FONT_PROPERTY_WIDTH,
	XL_FONT_PROPERTY_HEIGHT,
	XL_FONT_PROPERTY_SIZE,
	XL_FONT_PATH,

	XL_MATERIAL,
	XL_MATERIAL_METAHEADER_PATH,
	XL_MATERIAL_METAHEADER_MAGIC,
	XL_MATERIAL_METAHEADER_TYPE,
	XL_MATERIAL_METADATA_NAME,
	XL_MATERIAL_METADATA_VERSION,
	XL_MATERIAL_METADATA_AUTHOR,
	XL_MATERIAL_METADATA_DATE,
	XL_MATERIAL_METADATA_COPYRIGHT,
	XL_MATERIAL_METADATA_LICENSE,
	XL_MATERIAL_METADATA_URL,
	XL_MATERIAL_METADATA_EMAIL,
	XL_MATERIAL_METADATA_TOOL,
	XL_MATERIAL_METADATA_COMMENT,
	XL_MATERIAL_METADATA_XL,
	XL_MATERIAL_PROPERTIES,
	XL_MATERIAL_PROPERTY,
	XL_MATERIAL_PROPERTY_NAME,
	XL_MATERIAL_PROPERTY_IMAGE,
	XL_MATERIAL_PROPERTY_ALPHA,
	XL_MATERIAL_PROPERTY_AMBIENT,
	XL_MATERIAL_PROPERTY_DIFFUSE,
	XL_MATERIAL_PROPERTY_SPECULAR,
	XL_MATERIAL_PROPERTY_EMISSION,
	XL_MATERIAL_PROPERTY_SHININESS,
	XL_MATERIAL_PROPERTY_MATRIX,

	XL_SURFACE,
	XL_SURFACE_METAHEADER_PATH,
	XL_SURFACE_METAHEADER_MAGIC,
	XL_SURFACE_METAHEADER_TYPE,
	XL_SURFACE_METADATA_NAME,
	XL_SURFACE_METADATA_VERSION,
	XL_SURFACE_METADATA_AUTHOR,
	XL_SURFACE_METADATA_DATE,
	XL_SURFACE_METADATA_COPYRIGHT,
	XL_SURFACE_METADATA_LICENSE,
	XL_SURFACE_METADATA_URL,
	XL_SURFACE_METADATA_EMAIL,
	XL_SURFACE_METADATA_TOOL,
	XL_SURFACE_METADATA_COMMENT,
	XL_SURFACE_METADATA_XL,
	XL_SURFACE_MATERIAL,
	XL_SURFACE_FRAMES,
	XL_SURFACE_ACTIONS,
	XL_SURFACE_ACTION,
	XL_SURFACE_ACTION_NAME,
	XL_SURFACE_ACTION_FRAMES,
	XL_SURFACE_ACTION_FRAME,
	XL_SURFACE_ACTION_FRAME_MATRIX,
	XL_SURFACE_ACTION_FRAME_TIME,
	XL_SURFACE_MATRIX,

	XL_OBJECT,
	XL_OBJECT_METAHEADER_PATH,
	XL_OBJECT_METAHEADER_MAGIC,
	XL_OBJECT_METAHEADER_TYPE,
	XL_OBJECT_METADATA_NAME,
	XL_OBJECT_METADATA_VERSION,
	XL_OBJECT_METADATA_AUTHOR,
	XL_OBJECT_METADATA_DATE,
	XL_OBJECT_METADATA_COPYRIGHT,
	XL_OBJECT_METADATA_LICENSE,
	XL_OBJECT_METADATA_URL,
	XL_OBJECT_METADATA_EMAIL,
	XL_OBJECT_METADATA_TOOL,
	XL_OBJECT_METADATA_COMMENT,
	XL_OBJECT_METADATA_XL,
	XL_OBJECT_VERTICES,
	XL_OBJECT_MATERIALS,
	XL_OBJECT_FACES,
	XL_OBJECT_TAGS,
	XL_OBJECT_MATERIAL,
	XL_OBJECT_MATERIAL_MATERIAL,
	XL_OBJECT_MATERIAL_NAME,
	XL_OBJECT_MATERIAL_SURFACE,
	XL_OBJECT_TAG,
	XL_OBJECT_TAG_NAME,
	XL_OBJECT_TAG_MATRIX,
	//XL_OBJECT_BOUND_SPHERE,
	//XL_OBJECT_BOUND_BOX,
	XL_OBJECT_MATRIX,

	XL_MODEL,
	XL_MODEL_METAHEADER_PATH,
	XL_MODEL_METAHEADER_MAGIC,
	XL_MODEL_METAHEADER_TYPE,
	XL_MODEL_METADATA_NAME,
	XL_MODEL_METADATA_VERSION,
	XL_MODEL_METADATA_AUTHOR,
	XL_MODEL_METADATA_DATE,
	XL_MODEL_METADATA_COPYRIGHT,
	XL_MODEL_METADATA_LICENSE,
	XL_MODEL_METADATA_URL,
	XL_MODEL_METADATA_EMAIL,
	XL_MODEL_METADATA_TOOL,
	XL_MODEL_METADATA_COMMENT,
	XL_MODEL_METADATA_XL,
	XL_MODEL_BONES,
	XL_MODEL_PARENTS,
	XL_MODEL_VERTICES,
	XL_MODEL_TAGS,
	XL_MODEL_WEIGHTS,
	XL_MODEL_FRAMES,
	XL_MODEL_ACTIONS,
	XL_MODEL_ACTION,
	XL_MODEL_ACTION_NAME,
	XL_MODEL_ACTION_FRAMES,
	XL_MODEL_ACTION_FRAME,
	XL_MODEL_ACTION_FRAME_MATRIX,
	XL_MODEL_ACTION_FRAME_TIME,
	XL_MODEL_OBJECT,

	XL_PARTICLES,
	XL_PARTICLES_METAHEADER_PATH,
	XL_PARTICLES_METAHEADER_MAGIC,
	XL_PARTICLES_METAHEADER_TYPE,
	XL_PARTICLES_METADATA_NAME,
	XL_PARTICLES_METADATA_VERSION,
	XL_PARTICLES_METADATA_AUTHOR,
	XL_PARTICLES_METADATA_DATE,
	XL_PARTICLES_METADATA_COPYRIGHT,
	XL_PARTICLES_METADATA_LICENSE,
	XL_PARTICLES_METADATA_URL,
	XL_PARTICLES_METADATA_EMAIL,
	XL_PARTICLES_METADATA_TOOL,
	XL_PARTICLES_METADATA_COMMENT,
	XL_PARTICLES_METADATA_XL,
	XL_PARTICLES_COUNT,
	XL_PARTICLES_PARTICLE,
	XL_PARTICLES_PARTICLE_TYPE,
	XL_PARTICLES_PARTICLE_ENERGY,
	XL_PARTICLES_PARTICLE_MATRIX,
	XL_PARTICLES_PARTICLE_DATA,
	XL_PARTICLES_TYPE,
	XL_PARTICLES_ENERGY,
	XL_PARTICLES_MATRIX,
	XL_PARTICLES_DATA,

	XL_CAMERA,
	XL_CAMERA_METAHEADER_PATH,
	XL_CAMERA_METAHEADER_MAGIC,
	XL_CAMERA_METAHEADER_TYPE,
	XL_CAMERA_METADATA_NAME,
	XL_CAMERA_METADATA_VERSION,
	XL_CAMERA_METADATA_AUTHOR,
	XL_CAMERA_METADATA_DATE,
	XL_CAMERA_METADATA_COPYRIGHT,
	XL_CAMERA_METADATA_LICENSE,
	XL_CAMERA_METADATA_URL,
	XL_CAMERA_METADATA_EMAIL,
	XL_CAMERA_METADATA_TOOL,
	XL_CAMERA_METADATA_COMMENT,
	XL_CAMERA_METADATA_XL,
	XL_CAMERA_PROPERTIES,
	XL_CAMERA_PROPERTY,
	XL_CAMERA_PROPERTY_NAME,
	XL_CAMERA_PROPERTY_TYPE,
	XL_CAMERA_PROPERTY_LEFT,
	XL_CAMERA_PROPERTY_RIGHT,
	XL_CAMERA_PROPERTY_BOTTOM,
	XL_CAMERA_PROPERTY_TOP,
	XL_CAMERA_PROPERTY_FIELD_OF_VIEW,
	XL_CAMERA_PROPERTY_ASPECT,
	XL_CAMERA_PROPERTY_ZNEAR,
	XL_CAMERA_PROPERTY_ZFAR,
	XL_CAMERA_PROPERTY_MATRIX,
	XL_CAMERA_PROPERTY_PROJECTION,
	XL_CAMERA_PROPERTY_MODELVIEW,

	XL_OPERATOR,
	XL_OPERATOR_METAHEADER_PATH,
	XL_OPERATOR_METAHEADER_MAGIC,
	XL_OPERATOR_METAHEADER_TYPE,
	XL_OPERATOR_METADATA_NAME,
	XL_OPERATOR_METADATA_VERSION,
	XL_OPERATOR_METADATA_AUTHOR,
	XL_OPERATOR_METADATA_DATE,
	XL_OPERATOR_METADATA_COPYRIGHT,
	XL_OPERATOR_METADATA_LICENSE,
	XL_OPERATOR_METADATA_URL,
	XL_OPERATOR_METADATA_EMAIL,
	XL_OPERATOR_METADATA_TOOL,
	XL_OPERATOR_METADATA_COMMENT,
	XL_OPERATOR_METADATA_XL,
	XL_OPERATOR_CAMERA,
	XL_OPERATOR_FRAMES,
	XL_OPERATOR_ACTIONS,
	XL_OPERATOR_ACTION,
	XL_OPERATOR_ACTION_NAME,
	XL_OPERATOR_ACTION_FRAMES,
	XL_OPERATOR_ACTION_FRAME,
	XL_OPERATOR_ACTION_FRAME_MATRIX,
	XL_OPERATOR_ACTION_FRAME_TIME,
	XL_OPERATOR_MATRIX,

	XL_VIEWPORT,
	XL_VIEWPORT_METAHEADER_PATH,
	XL_VIEWPORT_METAHEADER_MAGIC,
	XL_VIEWPORT_METAHEADER_TYPE,
	XL_VIEWPORT_METADATA_NAME,
	XL_VIEWPORT_METADATA_VERSION,
	XL_VIEWPORT_METADATA_AUTHOR,
	XL_VIEWPORT_METADATA_DATE,
	XL_VIEWPORT_METADATA_COPYRIGHT,
	XL_VIEWPORT_METADATA_LICENSE,
	XL_VIEWPORT_METADATA_URL,
	XL_VIEWPORT_METADATA_EMAIL,
	XL_VIEWPORT_METADATA_TOOL,
	XL_VIEWPORT_METADATA_COMMENT,
	XL_VIEWPORT_METADATA_XL,
	XL_VIEWPORT_PROPERTIES,
	XL_VIEWPORT_PROPERTY,
	XL_VIEWPORT_PROPERTY_NAME,
	XL_VIEWPORT_PROPERTY_X,
	XL_VIEWPORT_PROPERTY_Y,
	XL_VIEWPORT_PROPERTY_POSITION,
	XL_VIEWPORT_PROPERTY_WIDTH,
	XL_VIEWPORT_PROPERTY_HEIGHT,
	XL_VIEWPORT_PROPERTY_SIZE,

	XL_WINDOW,
	XL_WINDOW_METAHEADER_PATH,
	XL_WINDOW_METAHEADER_MAGIC,
	XL_WINDOW_METAHEADER_TYPE,
	XL_WINDOW_METADATA_NAME,
	XL_WINDOW_METADATA_VERSION,
	XL_WINDOW_METADATA_AUTHOR,
	XL_WINDOW_METADATA_DATE,
	XL_WINDOW_METADATA_COPYRIGHT,
	XL_WINDOW_METADATA_LICENSE,
	XL_WINDOW_METADATA_URL,
	XL_WINDOW_METADATA_EMAIL,
	XL_WINDOW_METADATA_TOOL,
	XL_WINDOW_METADATA_COMMENT,
	XL_WINDOW_METADATA_XL,
	XL_WINDOW_PROPERTIES,
	XL_WINDOW_PROPERTY,
	XL_WINDOW_PROPERTY_NAME,
	XL_WINDOW_PROPERTY_TITLE,
	XL_WINDOW_PROPERTY_X,
	XL_WINDOW_PROPERTY_Y,
	XL_WINDOW_PROPERTY_POSITION,
	XL_WINDOW_PROPERTY_WIDTH,
	XL_WINDOW_PROPERTY_HEIGHT,
	XL_WINDOW_PROPERTY_SIZE
};

#undef _xlMatrixEnum
#undef _xlVectorEnum
#undef _xlColorEnum
#undef _xlPairEnum

struct _XLpair
{
#ifdef XL_SIMD
	union
	{
		XLsimd4sr simd;
#endif
		XLreal array[4];
#ifdef XL_SIMD
	} value;
#endif
}; 

struct _XLcolor
{
#ifdef XL_SIMD
	union
	{
		XLsimd4sr simd;
#endif
		XLreal array[4];
#ifdef XL_SIMD
	} value;
#endif
}; 

struct _XLpoint
{
#ifdef XL_SIMD
	union
	{
		XLsimd4sr simd;
#endif
		XLreal array[4];
#ifdef XL_SIMD
	} value;
#endif
}; 

struct _XLvector
{
#ifdef XL_SIMD
	union
	{
		XLsimd4sr simd;
#endif
		XLreal array[4];
#ifdef XL_SIMD
	} value;
#endif
}; 

struct _XLmatrix
{
#ifdef XL_SIMD
	union
	{
		XLsimd16sr simd;
#endif
		XLreal array[16];
#ifdef XL_SIMD
	} value;
#endif
};

struct _XLerror
{
	XLpath file;
	XLpath function;
	XLuint line;
	XLenum value;
};

struct _XLstore
{
	XLvoid *data[XL_STORE_SIZE];
	XLid ids[XL_STORE_SIZE];
	XLid bind;
};

struct _XLdata
{
	XLchar *path;
	XLuint (*data)(XLenum mode, const XLpath);
};

struct _XLmetaheader
{
	XLint magic;
	XLpath path;
};

struct _XLmetadata
{
	XLstring type;
	XLstring name;
	XLstring version;
	XLstring author;
	XLstring date;
	XLstring copyright;
	XLstring license;
	XLstring url;
	XLstring email;
	XLstring tool;
	XLstring comment;
	XLstring xl;
};

struct _XLrange
{
	XLuint start;
	XLuint count;
};

struct _XLImageHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint width;
	XLuint height;
	XLuint bpp;
};

struct _XLImageBody
{
	XLcolor *pixels;
};

struct _XLImageRuntime
{
	GLuint texture;
};

struct _XLimage
{
	XLImageHeader header;
	XLImageBody body;
	XLImageRuntime runtime;
};

struct _XLSoundHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint frequency;
	XLuint length;
	XLuint bps;
};

struct _XLSoundBody
{
	XLvoid *samples;
};

struct _XLSoundRuntime
{
	ALuint buffer;
	ALuint source;
};

struct _XLsound
{
	XLSoundHeader header;
	XLSoundBody body;
	XLSoundRuntime runtime;
};

struct _XLFontHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint properties;
};

struct _XLFontProperty
{
	XLstring name;
	XLuint width;
	XLuint height;
};

struct _XLFontBody
{
	XLFontProperty *properties;
	XLpath path;
};

struct _XLFontRuntime
{
	FT_Face face;
	XLuint property;
};

struct _XLfont
{
	XLFontHeader header;
	XLFontBody body;
	XLFontRuntime runtime;
};

struct _XLMaterialHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint properties;
};

struct _XLMaterialProperty
{
	XLstring name;
	XLpath image;
	XLreal alpha;
	XLcolor ambient;
	XLcolor diffuse;
	XLcolor specular;
	XLcolor emission;
	XLreal shininess;
	XLmatrix matrix;
};

struct _XLMaterialBody
{
	XLMaterialProperty *properties;
};

struct _XLMaterialRuntime
{
	XLid *images;
	XLuint property;
};

struct _XLmaterial
{
	XLMaterialHeader header;
	XLMaterialBody body;
	XLMaterialRuntime runtime;
};

struct _XLSurfaceHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint frames;
	XLuint actions;
};

struct _XLSurfaceMaterial
{
	XLpath path;
};

struct _XLSurfaceFrame
{
	XLmatrix matrix;
	XLreal time;
};

struct _XLSurfaceAction
{
	XLstring name;
	XLrange frames;
};

struct _XLSurfaceBody
{
	XLSurfaceMaterial *material;
	XLSurfaceFrame *frames;
	XLSurfaceAction *actions;
};

struct _XLSurfaceRuntime
{
	XLuint material;
	XLuint action, frame;
	XLreal time;
};

struct _XLsurface
{
	XLSurfaceHeader header;
	XLSurfaceBody body;
	XLSurfaceRuntime runtime;
};

struct _XLvertex
{
	XLpoint coord;
	XLvector normal;
	XLcolor color;
	XLpair tex;
};

struct _XLObjectHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint vertices;
	XLuint materials;
	XLuint faces;
	XLuint tags;
};

struct _XLObjectVertex
{
	XLpoint coord;
	XLvector normal;
};

struct _XLObjectMaterial
{
	XLstring name;
	XLpath path;
	XLuint surface;
	XLrange faces;
};

struct _XLObjectFace
{
	XLuint vertices[3];
	XLvector normal;
	XLpair texcoords[3];
};

struct _XLObjectTag
{
	XLstring name;
	XLmatrix matrix;
};

struct _XLObjectBound
{
	XLreal sphere[4];
	XLreal dimensions[3];
};

struct _XLObjectBody
{
	XLObjectVertex *vertices;
	XLObjectMaterial *materials;
	XLObjectFace *faces;
	XLObjectTag *tags;
	XLObjectBound *bound;
};

struct _XLObjectRuntime
{
	XLuint *materials;
	XLuint material, tag;
	XLvertex *vertices;
	XLmatrix matrix;
};

struct _XLobject
{
	XLObjectHeader header;
	XLObjectBody body;
	XLObjectRuntime runtime;
};

struct _XLModelHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint bones;
	XLuint parents;
	XLuint vertices;
	XLuint tags;
	XLuint weights;
	XLuint frames;
	XLuint actions;
};

struct _XLModelObject
{
	XLpath path;
};

struct _XLModelBone
{
	XLstring name;
	XLrange parents;
};

struct _XLModelParent
{
	XLuint bone;
};

struct _XLModelVertex
{
	XLrange weights;
};

struct _XLModelWeight
{
	XLuint bone;
	XLreal value;
};

struct _XLModelTag
{
	XLrange weights;
};

struct _XLModelBoneFrame
{
	XLmatrix matrix;
};

struct _XLModelFrame
{
	XLModelBoneFrame *bones;
	XLmatrix matrix;
	XLreal time;
};

struct _XLModelAction
{
	XLstring name;
	XLrange frames;
};

struct _XLModelBody
{
	XLModelObject *object;
	XLModelBone *bones;
	XLModelParent *parents;
	XLModelVertex *vertices;
	XLModelTag *tags;
	XLModelWeight *weights;
	XLModelFrame *frames;
	XLModelAction *actions;
};

struct _XLModelRuntime
{
	XLuint object;
	XLuint action[2], frame[2], morph, blend;
	XLreal morphfactor, blendfactor;
	XLpoint *(anim[3]);
	XLreal time[2];
};

struct _XLmodel
{
	XLModelHeader header;
	XLModelBody body;
	XLModelRuntime runtime;
};

struct _XLParticlesHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
};

struct _XLparticle
{
	XLint type;
	XLreal energy;
	XLmatrix matrix;
	void *data;
};

struct _XLParticlesBody
{
	XLuint count;
};

struct _XLParticlesRuntime
{
	XLparticle *particles;
	XLparticle global;
	XLuint particle;
};

struct _XLparticles
{
	XLParticlesHeader header;
	XLParticlesBody body;
	XLParticlesRuntime runtime;
};

struct _XLCameraHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint properties;
};

struct _XLCameraProperty
{
	XLstring name;
	enum
	{
		XL_CAMERA_NONE = 0,
		XL_CAMERA_PROPERTY_ORTHOGONAL,
		XL_CAMERA_PROPERTY_PERSPECTIVE
	} type;
	union
	{
		struct
		{
			XLreal left, right;
			XLreal bottom, top;
		} orthogonal;
		struct
		{
			XLreal fovy;
			XLreal aspect;
			XLreal znear, zfar;
		} perspective;
	} details;
	XLmatrix matrix;
	XLmatrix projection;
	XLmatrix modelview;
};

struct _XLCameraBody
{
	XLCameraProperty *properties;
};

struct _XLCameraRuntime
{
	XLreal frustum[24];
	XLuint property;
};

struct _XLcamera
{
	XLCameraHeader header;
	XLCameraBody body;
	XLCameraRuntime runtime;
};

struct _XLOperatorHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint frames;
	XLuint actions;
};

struct _XLOperatorCamera
{
	XLpath path;
};

struct _XLOperatorFrame
{
	XLmatrix matrix;
	XLreal time;
};

struct _XLOperatorAction
{
	XLstring name;
	XLrange frames;
};

struct _XLOperatorBody
{
	XLOperatorCamera *camera;
	XLOperatorFrame *frames;
	XLOperatorAction *actions;
};

struct _XLOperatorRuntime
{
	XLuint camera;
	XLuint action, frame;
	XLreal time;
};

struct _XLoperator
{
	XLOperatorHeader header;
	XLOperatorBody body;
	XLOperatorRuntime runtime;
};

struct _XLViewportHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint properties;
};

struct _XLViewportProperty
{
	XLstring name;
	XLpair position;
	XLpair size;
};

struct _XLViewportBody
{
	XLViewportProperty *properties;
};

struct _XLViewportRuntime
{
	XLuint property;
};

struct _XLviewport
{
	XLViewportHeader header;
	XLViewportBody body;
	XLViewportRuntime runtime;
};

struct _XLWindowHeader
{
	XLmetaheader metaheader;
	XLmetadata metadata;
	XLuint properties;
};

struct _XLWindowProperty
{
	XLstring name;
	XLstring title;
	XLpair position;
	XLpair size;
};

struct _XLWindowBody
{
	XLWindowProperty *properties;
};

struct _XLWindowRuntime
{
	XLuint property;
};

struct _XLwindow
{
	XLWindowHeader header;
	XLWindowBody body;
	XLWindowRuntime runtime;
};

extern XLstring
	xlXL,
	xlVendor,
	xlRenderer,
	xlVersion,
	xlName,
	xlDescription,
	xlAuthor,
	xlDate,
	xlCopyright,
	xlLicense,
	xlUrl,
	xlEmail,
	xlTool;

XLerror
	xlError;

extern XLenum
	xlLogLevel;

extern XLreal
	xlTimeTotal,
	xlTimeDelta;

extern XLstore xlStores;

extern XLid xlBinds;
extern XLid xlBuffers;

extern XLid
	xlMetaHeaders,
	xlMetaDatas,
	xlImages,
	xlSounds,
	xlFonts,
	xlMaterials,
	xlSurfaces,
	xlObjects,
	xlModels,
	xlParticles,
	xlCameras,
	xlOperators,
	xlViewports,
	xlWindows;

extern XLdata
	xlDatas[XL_STORE_SIZE];

extern magic_t
	xlMagicCookie,
	xlMagicCompressCookie;

extern FT_Library
	xlFontLibrary;

#endif
