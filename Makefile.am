ACLOCAL_AMFLAGS = -I autoconf.macro
SUBDIRS = src tools doc demos games apps
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = xl.pc
dist_doc_DATA = README NEWS AUTHORS COPYING ChangeLog NOTES PAYMENTS

deep:
	make && make clean && make 

deepdistcheck: deep
	make distcheck
