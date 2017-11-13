dnl @configure_input@
dnl

AC_PREREQ([2.69])
AC_INIT([CCTemplate],[0.1.0-devel.0],
  [marco.maggi-ipsu@poste.it],
  [cctemplate],[http://marcomaggi.github.com/cctemplate])
dnl This is the revision number of this configure.ac
AC_REVISION([0.1])
AC_COPYRIGHT([Copyright (c) 2016, 2017 Marco Maggi <marco.maggi-ipsu@poste.it>

This program is free software: you  can redistribute it and/or modify it
under the  terms of the GNU  General Public License as  published by the
Free Software Foundation,  either version 3 of the License,  or (at your
option) any later version.

This program  is distributed  in the  hope that it  will be  useful, but
WITHOUT   ANY   WARRANTY;  without   even   the   implied  warranty   of
MERCHANTABILITY  or  FITNESS FOR  A  PARTICULAR  PURPOSE.  See  the  GNU
General Public License for more details.

You should have received a copy  of the GNU General Public License along
with this program.  If not, see <http://www.gnu.org/licenses/>.
])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_MACRO_DIR([meta/autotools])
AC_CONFIG_AUX_DIR([meta/autotools])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([foreign dist-xz no-dist-gzip subdir-objects])
AM_MAINTAINER_MODE

AM_PROG_AR
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P

LT_PREREQ([2.4])
LT_INIT

dnl page
#### libraries interface version

AS_VAR_SET([SLACKSTUFF_PACKAGE_VERSION],[0.1d0.0])
AC_SUBST([SLACKSTUFF_PACKAGE_VERSION])

dnl This is the version stored in the pkg-config data file.
AC_SUBST([CCTEMPLATE_PKG_CONFIG_VERSION],[0.1])

MM_LIBTOOL_LIBRARY_VERSIONS([cctemplate],1,0,0)

dnl page
#### basic system inspection

AC_LANG([C])
dnl AC_PROG_CC
AC_PROG_CC_C99
AX_CHECK_COMPILE_FLAG([-std=c11],[],[AC_MSG_ERROR([*** Compiler does not support -std=c11])],[-pedantic])

AS_VAR_SET(AX_CFLAGS,[-std=c11])
AS_VAR_APPEND(AX_CFLAGS,[" -Wall -Wextra"])
AX_GCC_VERSION
AS_IF([test "x$GCC" = "xyes"],
  [AS_CASE("$GCC_VERSION",
     [7.*],[AS_VAR_APPEND(AX_CFLAGS,[" -pedantic -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference -Wjump-misses-init -Wdouble-promotion -Wshadow -Wformat=2 -Wmisleading-indentation"])])])
AC_SUBST(AX_CFLAGS)

AM_PROG_AS
AM_PROG_CC_C_O
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([assert.h stdint.h strings.h errno.h stddef.h sys/mman.h sys/resource.h unistd.h])
AC_CHECK_SIZEOF(void *)
AC_C_CONST
AC_C_INLINE
AC_C_RESTRICT
AC_TYPE_LONG_LONG_INT
AC_TYPE_UNSIGNED_LONG_LONG_INT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

dnl MM_CHECK_PAGESIZE
dnl AC_DEFINE_UNQUOTED([CCG_PAGESIZE],[$MM_cv_pagesize],[Platform page size.])
dnl MM_CHECK_PAGESHIFT($mm_cv_pagesize)
dnl AC_DEFINE_UNQUOTED([CCG_PAGESHIFT],[$MM_cv_pageshift],[Page shift bit count.])

dnl AC_LANG([C++])
dnl AC_PROG_CXX

AC_CACHE_SAVE

dnl page
#### checks for library functions

AC_FUNC_MALLOC
AC_FUNC_MEMCMP
dnl AC_CHECK_FUNCS([memmove memset strerror])
dnl AC_CHECK_FUNCS([mmap munmap msync mremap madvise mlock munlock mlockall munlockall mprotect])
dnl AC_CHECK_FUNCS([getenv])

AC_CACHE_SAVE

dnl page
#### external libraries

dnl AX_PTHREAD(,[AC_MSG_ERROR([cannot find pthread library],[1])])

dnl PKG_CHECK_MODULES([GSL],[gsl >= 1.16],[gsl=yes],[gsl=no])
dnl GSL_CPPFLAGS=$(pkg-config gsl --cflags)
dnl GSL_LDFLAGS=$(pkg-config gsl --libs)

dnl AC_CHECK_HEADERS([gmp.h],,[AC_MSG_ERROR([Cannot find libgmp.])])
dnl AC_CHECK_LIB([gmp],[__gmpn_add],,[AC_MSG_ERROR([Cannot find libgmp.])])

dnl AC_CACHE_SAVE

dnl page
#### operating system specific configuration

dnl AS_CASE("$target_os",
dnl   [*linux*],[],
dnl   [*bsd*],[],
dnl   [*cygwin*],[],
dnl   [*darwin*],[cctemplate_OS_DARWIN=yes])
dnl AM_CONDITIONAL([WANT_LINUX], [test "x$cctemplate_OS_LINUX"  = xyes])
dnl AM_CONDITIONAL([WANT_BSD],   [test "x$cctemplate_OS_BSD"    = xyes])
dnl AM_CONDITIONAL([WANT_CYGWIN],[test "x$cctemplate_OS_CYGWIN" = xyes])
dnl AM_CONDITIONAL([WANT_DARWIN],[test "x$cctemplate_OS_DARWIN" = xyes])

dnl page
#### finish

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile]
   [meta/scripts/cctemplate.pc]
   [meta/slackstuff/config]
   [meta/slackware/slack-desc])
AC_OUTPUT

### end of file
# Local Variables:
# mode: autoconf
# page-delimiter: "^dnl page"
# End:
