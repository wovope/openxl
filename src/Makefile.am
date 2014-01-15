lib_LTLIBRARIES = libxl.la
nobase_include_HEADERS = \
	XL/xl.h \
	XL/xlMacros.h \
	XL/xlTypes.h \
	XL/xlError.h \
	XL/xlLog.h \
	XL/xlDebug.h \
	XL/xlUtils.h \
	XL/xlPair.h \
	XL/xlColor.h \
	XL/xlPoint.h \
	XL/xlVector.h \
	XL/xlMatrix.h \
	XL/xlSphere.h \
	XL/xlData.h \
	XL/xlParser.h \
	XL/xlGet.h \
	XL/xlSet.h \
	XL/xlGen.h \
	XL/xlDelete.h \
	XL/xlBind.h \
	XL/xlType.h \
	XL/xlLoad.h \
	XL/xlUnload.h \
	XL/xlSave.h \
	XL/xlCompile.h \
	XL/xlDecompile.h \
	XL/xlImport.h \
	XL/xlExport.h \
	XL/xlSync.h \
	XL/xlDraw.h \
	XL/id.h XL/unid.h \
	XL/xlImage.h \
	XL/xlFont.h \
	XL/xlMaterial.h \
	XL/xlSurface.h \
	XL/xlObject.h \
	XL/xlModel.h \
	XL/xlParticles.h \
	XL/xlCamera.h \
	XL/xlOperator.h \
	XL/xlViewport.h \
	XL/xlWindow.h \
	XL/xlPipeline.h \
	XL/xlPort.h \
	XL/xlTexturizer.h \
	XL/FL/xlflut.h \
	XL/GL/xlglut.h \
	XL/AL/xlalut.h
EXTRA_DIST = \
	XL/xlWorld.h \
	xlWorld.c
libxl_la_SOURCES = \
	XL/xlMacros.h xlMacros.c \
	XL/xlTypes.h xlTypes.c \
	XL/xlError.h xlError.c \
	XL/xlLog.h xlLog.c \
	XL/xlDebug.h xlDebug.c \
	XL/xlUtils.h xlUtils.c \
	XL/xlPair.h xlPair.c \
	XL/xlColor.h xlColor.c \
	XL/xlPoint.h xlPoint.c \
	XL/xlVector.h xlVector.c \
	XL/xlMatrix.h xlMatrix.c \
	XL/xlSphere.h xlSphere.c \
	XL/xlData.h xlData.c \
	XL/xlParser.h xlParser.c \
	XL/xlGet.h xlGet.c \
	XL/xlSet.h xlSet.c \
	XL/xlGen.h xlGen.c \
	XL/xlDelete.h xlDelete.c \
	XL/xlBind.h xlBind.c \
	XL/xlType.h xlType.c \
	XL/xlLoad.h xlLoad.c \
	XL/xlUnload.h xlUnload.c \
	XL/xlSave.h xlSave.c \
	XL/xlCompile.h xlCompile.c \
	XL/xlDecompile.h xlDecompile.c \
	XL/xlImport.h xlImport.c \
	XL/xlExport.h xlExport.c \
	XL/xlSync.h xlSync.c \
	XL/xlDraw.h xlDraw.c \
	XL/xlImage.h xlImage.c \
	XL/xlSound.h xlSound.c \
	XL/xlFont.h xlFont.c \
	XL/xlMaterial.h xlMaterial.c \
	XL/xlSurface.h xlSurface.c \
	XL/xlObject.h xlObject.c \
	XL/xlModel.h xlModel.c \
	XL/xlParticles.h xlParticles.c \
	XL/xlCamera.h xlCamera.c \
	XL/xlOperator.h xlOperator.c \
	XL/xlViewport.h xlViewport.c \
	XL/xlWindow.h xlWindow.c \
	XL/xlPipeline.h xlPipeline.c \
	XL/xlPort.h xlPort.c \
	XL/xlTexturizer.h xlTexturizer.c \
	XL/id.h XL/unid.h \
	XL/FL/flSound.h FL/flSound.c \
	XL/FL/xlflut.h \
	XL/GL/xlglut.h \
	XL/AL/xlalut.h \
	XL/xl.h xl.c
libxl_la_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
  	-I$(top_srcdir) \
	-I. 
libxl_la_LIBADD = \
	$(XL_DEPS_LIBS)
