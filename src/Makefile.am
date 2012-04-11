## Process this file with automake to produce Makefile.in

AM_CFLAGS="-Wall"

cctemplate_CURRENT	= @cctemplate_VERSION_INTERFACE_CURRENT@
cctemplate_REVISION	= @cctemplate_VERSION_INTERFACE_REVISION@
cctemplate_AGE		= @cctemplate_VERSION_INTERFACE_AGE@

include_HEADERS		= cctemplate.h

lib_LTLIBRARIES		= libcctemplate.la
libcctemplate_la_LDFLAGS= -version-info $(cctemplate_CURRENT):$(cctemplate_REVISION):$(cctemplate_AGE)
libcctemplate_la_SOURCES= cctemplate-version.c

### end of file
