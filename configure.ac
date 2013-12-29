AC_INIT([X Library], [2013.12.24], [juanmabcmail@gmail.com], [xl], ["http://code.google.com/p/openxl"])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE(no-dist-gzip dist-bzip2)

AC_SUBST(PACKAGE_AUTHOR, ["Juan Manuel Borges Caño"])
AC_SUBST(PACKAGE_DESCRIPTION, ["Multiple Purpose C Open Game Engine"])
AC_SUBST(PACKAGE_URL, ["http://code.google.com/p/openxl"])
AC_SUBST(PACKAGE_MONTH, [$(LANG=C date '+%B')])
AC_SUBST(PACKAGE_YEAR, [$(LANG=C date '+%Y')])
AC_SUBST(PACKAGE_DATE, [$(LANG=C date)])
AC_SUBST(PACKAGE_COPYRIGHT, ["2012, 2013 Juan Manuel Borges Caño"])

AC_SUBST(PACKAGE_PARSE, ["sed -e 's,\@<:@@\@:>@pkg\@<:@@\@:>@,\$(PACKAGE),g' -e 's,\@<:@@\@:>@pkgname\@<:@@\@:>@,\$(PACKAGE_NAME),g' -e 's,\@<:@@\@:>@pkgversion\@<:@@\@:>@,\$(PACKAGE_VERSION),g' -e 's,\@<:@@\@:>@pkgauthor\@<:@@\@:>@,\$(PACKAGE_AUTHOR),g' -e 's,\@<:@@\@:>@pkgmonth\@<:@@\@:>@,\$(PACKAGE_MONTH),g' -e 's,\@<:@@\@:>@pkgyear\@<:@@\@:>@,\$(PACKAGE_YEAR),g' -e 's,\@<:@@\@:>@pkgurl\@<:@@\@:>@,\$(PACKAGE_URL),g' -e 's,\@<:@@\@:>@pkgbugreport\@<:@@\@:>@,\$(PACKAGE_BUGREPORT),g' -e 's/\@<:@@\@:>@pkgdescription\@<:@@\@:>@/\$(PACKAGE_DESCRIPTION)/g' -e 's,\@<:@@\@:>@pkgdatadir\@<:@@\@:>@,\$(pkgdatadir),g'"])

AC_DEFINE(PACKAGE_AUTHOR, ["Juan Manuel Borges Caño"], [Define to the full name author of this package.])
AC_DEFINE(PACKAGE_URL, ["http://code.google.com/p/openxl"], [Define to the full url of this package.])
AC_DEFINE(PACKAGE_DATE, ["Jun 2013"], [Define to the full date of this package.])
AC_DEFINE(PACKAGE_COPYRIGHT, ["2012, 2013 Juan Manuel Borges Caño"], [Define to the full copyright of this package.])
AC_DEFINE(PACKAGE_LICENSE, ["GNU General Public License, Version 3, 29 June 2007 (GPLv3+)"], [Define to the full license of this package.])
AC_DEFINE(PACKAGE_DESCRIPTION, ["Multiple Purpose C Open Engine"], [Define to the full description of this package.])
AC_DEFINE(PACKAGE_TOOL, ["openxl - Open X Library, Multiple Purpose C Open Engine"], [Define to the full tool tag of this package.])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_LIBTOOL

# Checks for libraries.
DEP_MODULES="libm xlflut xlglut xlalut"
PKG_CHECK_MODULES(XL_DEPS, $DEP_MODULES)
AC_SUBST(XL_DEPS_CFLAGS)
AC_SUBST(XL_DEPS_LIBS)

# Checks for header files.
AC_STDC_HEADERS

# Checks for typedefs, structures, and compiler characteristics.
XL_REAL_CFLAGS="-DXL_REAL_TYPE_FLOAT"
#XL_REAL_CFLAGS="-DXL_REAL_TYPE_DOUBLE"
AC_SUBST(XL_REAL_CFLAGS)

XL_SIMD_CFLAGS="-march=native -DXL_SIMD"
#XL_SIMD_CFLAGS=""
AC_SUBST(XL_SIMD_CFLAGS)

XL_CFLAGS="-D_ISOC11_SOURCE -D_XOPEN_SOURCE=500 -DXL_DEBUG"
#XL_CFLAGS="-D_ISOC11_SOURCE -D_XOPEN_SOURCE=500 -DXL_RELEASE"
AC_SUBST(XL_CFLAGS)

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile xl.pc tools/Makefile doc/Makefile demos/Makefile apps/Makefile apps/xlTerminal/Makefile games/Makefile games/xlSpaceWars/Makefile games/xlToyMachines/Makefile])
AC_OUTPUT
