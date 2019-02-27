## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL configure.sh		\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= $(MMUX_CFLAGS)
AM_CPPFLAGS		= -I$(srcdir)/src

## --------------------------------------------------------------------

nodist_pkgconfig_DATA	= meta/scripts/cctemplate.pc


#### documentation

AM_MAKEINFOFLAGS	= --no-split
AM_MAKEINFOHTMLFLAGS	= --split=node -c WORDS_IN_PAGE=0 \
	-c PRE_BODY_CLOSE="<p>This document describes version <tt>$(PACKAGE_VERSION)</tt> of <em>$(PACKAGE_NAME)</em>.</p>"

info_TEXINFOS		= doc/cctemplate.texi
doc_cctemplate_TEXINFOS	= \
	doc/overview-linking.texi	\
	doc/overview-ccnames.texi	\
	doc/overview-ccexceptions.texi	\
	doc/overview-ccmemory.texi	\
	doc/macros.texi			\
	doc/lgpl-3.0.texi		\
	doc/fdl-1.3.texi


#### libraries

cctemplate_CURRENT		= @cctemplate_VERSION_INTERFACE_CURRENT@
cctemplate_REVISION		= @cctemplate_VERSION_INTERFACE_REVISION@
cctemplate_AGE			= @cctemplate_VERSION_INTERFACE_AGE@
cctemplate_LINKER_VERSION	= -version-info $(cctemplate_CURRENT):$(cctemplate_REVISION):$(cctemplate_AGE)

include_HEADERS		= src/cctemplate.h

lib_LTLIBRARIES			= libcctemplate.la
libcctemplate_la_CPPFLAGS	= $(AM_CPPFLAGS)
libcctemplate_la_CFLAGS		= $(AM_CFLAGS) $(CCEXCEPTIONS_CFLAGS) $(CCMEMORY_CFLAGS) $(CCSTRUCTS_CFLAGS)
libcctemplate_la_LDFLAGS	= $(cctemplate_LINKER_VERSION) $(AM_LDFLAGS) $(CCEXCEPTIONS_LIBS) $(CCMEMORY_LIBS) $(CCSTRUCTS_LIBS)
libcctemplate_la_SOURCES	= \
	src/cctemplate.h		\
	src/cctemplate-internals.h	\
	src/cctemplate-library.c	\
	src/cctemplate-conditions.c


#### tests

check_PROGRAMS	= \
	tests/version				\
	tests/condition-objects

if MMUX_TESTING_ENABLED
TESTS				= $(check_PROGRAMS)
endif

cctemplate_tests_cppflags	= $(AM_CPPFLAGS) -I$(srcdir)/tests
cctemplate_tests_cflags		= $(AM_CFLAGS) $(CCEXCEPTIONS_CFLAGS) $(CCMEMORY_CFLAGS) $(CCSTRUCTS_CFLAGS) $(CCTESTS_CFLAGS)
cctemplate_tests_ldadd		= $(AM_LDFLAGS) libcctemplate.la $(CCEXCEPTIONS_LIBS) $(CCMEMORY_LIBS) $(CCSTRUCTS_LIBS) $(CCTESTS_LIBS)

## --------------------------------------------------------------------

tests_version_CPPFLAGS		= $(cctemplate_tests_cppflags)
tests_version_CFLAGS		= $(cctemplate_tests_cflags)
tests_version_LDADD		= $(cctemplate_tests_ldadd)

tests_condition_objects_CPPFLAGS	= $(cctemplate_tests_cppflags)
tests_condition_objects_CFLAGS		= $(cctemplate_tests_cflags)
tests_condition_objects_LDADD		= $(cctemplate_tests_ldadd)
tests_condition_objects_SOURCES		= \
	tests/condition-objects.c			\
	tests/condition-subtyping-some-error-body.c	\
	tests/condition-subtyping-some-error-header.h

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done


#### common rules

include $(top_srcdir)/meta/automake/mmux-makefile-rules

### end of file
