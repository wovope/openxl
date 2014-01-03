bin_PROGRAMS = \
	xlAdventure

xlAdventure_SOURCES = \
	xlAdventure.c
xlAdventure_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
	-I$(top_srcdir)/src
xlAdventure_LDADD = \
	$(top_builddir)/src/libxl.la

