EXTRA_DIST = \
	pkgconfig/libm.pc \
	pkgconfig/magic.pc \
	pkgconfig/ffmpeg.pc \
	pkgconfig/libbzip2.pc \
	pkgconfig/xlflut.pc \
	pkgconfig/xlglut.pc \
	pkgconfig/xlalut.pc \
	gimp/xl.scm \
	gimp/xl-gimp \
	gimp/xl-gimp-images \
	gimp/xl-gimp-images-batch \
	gimp/README \
	gimp/README.tp \
	blender/io_export_xlmaterial.py \
	blender/io_export_xlobject.py \
	blender/io_export_xlmodel.py

bin_PROGRAMS = \
	xlinfo \
	xlc \
	xld

TESTS = \
	xlinfo

xlinfo_SOURCES = \
	xlinfo.c
xlinfo_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
	-I$(top_srcdir)/src
xlinfo_LDADD = \
	$(top_builddir)/src/libxl.la

xlc_SOURCES = \
	xlc.c
xlc_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
	-I$(top_srcdir)/src
xlc_LDADD = \
	$(top_builddir)/src/libxl.la

xld_SOURCES = \
	xld.c
xld_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
	-I$(top_srcdir)/src
xld_LDADD = \
	$(top_builddir)/src/libxl.la

