## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL configure.sh		\
			  meta/slackstuff/config.in	\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= -I$(srcdir)/src $(AX_CFLAGS)

## --------------------------------------------------------------------

EXTRA_DIST		+= meta/scripts/cctemplate.pc.in
pkgconfigdir		= $(libdir)/pkgconfig
nodist_pkgconfig_DATA	= meta/scripts/cctemplate.pc

## --------------------------------------------------------------------

AM_MAKEINFOFLAGS	= --no-split

info_TEXINFOS		= doc/cctemplate.texi
doc_cctemplate_TEXINFOS	= \
	doc/macros.texi		\
	doc/gpl-3.0.texi	\
	doc/fdl-1.3.texi


#### libraries

cctemplate_CURRENT	= @cctemplate_VERSION_INTERFACE_CURRENT@
cctemplate_REVISION	= @cctemplate_VERSION_INTERFACE_REVISION@
cctemplate_AGE		= @cctemplate_VERSION_INTERFACE_AGE@

include_HEADERS		= src/cctemplate.h

lib_LTLIBRARIES			= libcctemplate.la
libcctemplate_la_CPPFLAGS	= $(CCEXCEPTIONS_CFLAGS) $(CCMEMORY_CFLAGS)
libcctemplate_la_LDFLAGS	= \
	-version-info $(cctemplate_CURRENT):$(cctemplate_REVISION):$(cctemplate_AGE) \
	$(CCEXCEPTIONS_LIBS) $(CCMEMORY_LIBS)
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

cctemplate_tests_cppflags	= -I$(srcdir)/src -I$(srcdir)/tests \
	$(CCEXCEPTIONS_CFLAGS) $(CCMEMORY_CFLAGS) $(CCTESTS_CFLAGS)
cctemplate_tests_ldadd		= libcctemplate.la \
	$(CCEXCEPTIONS_LIBS) $(CCMEMORY_LIBS) $(CCTESTS_LIBS)

## --------------------------------------------------------------------

tests_version_CPPFLAGS		= $(cctemplate_tests_cppflags)
tests_version_LDADD		= $(cctemplate_tests_ldadd)

tests_condition_objects_CPPFLAGS	= $(cctemplate_tests_cppflags)
tests_condition_objects_LDADD		= $(cctemplate_tests_ldadd)
tests_condition_objects_SOURCES		= \
	tests/condition-objects.c			\
	tests/condition-subtyping-some-error-body.c	\
	tests/condition-subtyping-some-error-header.h

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done


#### testing under GDB

$(builddir)/.gdbinit:
	ln -sv "$(top_srcdir)/gdbinit" "$(builddir)/.gdbinit"

# This rule is meant to be used as:
#
#   $ make all gdb-test FILE=tests/inspection CFLAGS='-g'
#
# after having created an appropriate file "$(top_srcdir)/.gdbinit".
#
gdb-test: $(builddir)/.gdbinit
	libtool --mode=execute gdb $$FILE


#### Static analysis with Clang's Static Analyzer
#
# See the documentation for the command line tool at:
#
#    <http://clang-analyzer.llvm.org/scan-build.html>
#
# To run the tool we must do:
#
#    $ make clean
#    $ make clang-static-analysis
#
# The  program  "scan-build"  works  by  overriding  the  CC  and  CXX
# environment variables.  Automake defines CXX as:
#
#    CXX = g++ -std=c++11
#
# so we override CXXFLAGS to include the language specification.
#

.PHONY: clang-static-analysis

clang-static-analysis:
	scan-build make CXXFLAGS='-std=c++11'

### end of file
