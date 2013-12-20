bin_PROGRAMS = \
	xlToyMachines

xlToyMachines_SOURCES = \
	xlToyMachines.c
xlToyMachines_CPPFLAGS = \
	-Wall \
	$(XL_DEPS_CFLAGS) \
	$(XL_REAL_CFLAGS) \
	$(XL_SIMD_CFLAGS) \
	$(XL_CFLAGS) \
	-I$(top_srcdir)/src
xlToyMachines_LDADD = \
	$(top_builddir)/src/libxl.la

