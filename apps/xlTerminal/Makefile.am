bin_PROGRAMS = \
	xlTerminal

xlTerminal_SOURCES = \
	xlTerminal.c
xlTerminal_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
	-I$(top_srcdir)/src
xlTerminal_LDADD = \
	$(top_builddir)/src/libxl.la

