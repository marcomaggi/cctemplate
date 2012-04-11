# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.68)
AC_INIT([CCTemplate],[0.1d0],[marco.maggi-ipsu@poste.it],
  [cctemplate],[http://marcomaggi.github.com/cctemplate.html])
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE
LT_PREREQ([2.4.2])
LT_INIT
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE

AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

#page
#### interface version

cctemplate_VERSION_INTERFACE_CURRENT=0
cctemplate_VERSION_INTERFACE_REVISION=0
cctemplate_VERSION_INTERFACE_AGE=0
AC_DEFINE_UNQUOTED([cctemplate_VERSION_INTERFACE_CURRENT],
  [$cctemplate_VERSION_INTERFACE_CURRENT],
  [current interface number])
AC_DEFINE_UNQUOTED([cctemplate_VERSION_INTERFACE_REVISION],
  [$cctemplate_VERSION_INTERFACE_REVISION],
  [current interface implementation number])
AC_DEFINE_UNQUOTED([cctemplate_VERSION_INTERFACE_AGE],
  [$cctemplate_VERSION_INTERFACE_AGE],
  [current interface age number])
AC_DEFINE_UNQUOTED([cctemplate_VERSION_INTERFACE_STRING],
  ["$cctemplate_VERSION_INTERFACE_CURRENT.$cctemplate_VERSION_INTERFACE_REVISION"],
  [library interface version])
AC_SUBST([cctemplate_VERSION_INTERFACE_CURRENT])
AC_SUBST([cctemplate_VERSION_INTERFACE_REVISION])
AC_SUBST([cctemplate_VERSION_INTERFACE_AGE])

#page
#### basic system inspection

AC_LANG([C])
AC_PROG_CC_C99
AM_PROG_AS
AC_PROG_CC
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

dnl CCTEMPLATE_CHECK_PAGESIZE
dnl AC_DEFINE_UNQUOTED([CCG_PAGESIZE],[$cctemplate_cv_pagesize],[Platform page size.])
dnl CCTEMPLATE_CHECK_PAGESHIFT($cctemplate_cv_pagesize)
dnl AC_DEFINE_UNQUOTED([CCG_PAGESHIFT],[$cctemplate_cv_pageshift],[Page shift bit count.])

AC_CACHE_SAVE

#page
#### checks for library functions

AC_FUNC_MALLOC
AC_FUNC_MEMCMP
dnl AC_CHECK_FUNCS([memmove memset strerror])
dnl AC_CHECK_FUNCS([mmap munmap msync mremap madvise mlock munlock mlockall munlockall mprotect])
dnl AC_CHECK_FUNCS([getenv])

AC_CACHE_SAVE

#page
#### external libraries

dnl AC_CHECK_HEADERS([gmp.h],,[AC_MSG_ERROR([Cannot find libgmp.])])
dnl AC_CHECK_LIB([gmp],[__gmpn_add],,[AC_MSG_ERROR([Cannot find libgmp.])])

dnl AC_CACHE_SAVE

#page
#### finish

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES(Makefile src/Makefile doc/Makefile tests/Makefile)
AC_OUTPUT

### end of file
# Local Variables:
# mode: autoconf
# page-delimiter: "^#page"
# End:
