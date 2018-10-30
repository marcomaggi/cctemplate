## mmux-lang-c11.m4 --
#
# Define the appropriate flags to  use the C11 standard language.  Store
# the appropriate compiler flags into the variable PKG_CFLAGS.  We should
# add such variables to the compile commands as follows in Makefile.am:
#
#   AM_CFLAGS = $(PKG_CFLAGS)
#
# If the C compiler is GCC: test and add some compiler specific flags.
#
# This macro is meant to be used as:
#
#       AC_LANG([C])
#       MMUX_LANG_C11
#

AC_DEFUN([MMUX_LANG_C11],[
  AX_REQUIRE_DEFINED([AX_CHECK_COMPILE_FLAG])
  AX_REQUIRE_DEFINED([AX_APPEND_COMPILE_FLAGS])
  AX_REQUIRE_DEFINED([AX_GCC_VERSION])
  AC_PROG_CC_C99
  AX_CHECK_COMPILE_FLAG([-std=c11],
    [AX_APPEND_FLAG([-std=c11], [CC])],
    [AC_MSG_ERROR([*** Compiler does not support -std=c11])],
    [-pedantic])

  AX_GCC_VERSION
  AC_SUBST([PKG_CFLAGS])
  AS_VAR_IF(GCC,'yes',
    [AX_APPEND_COMPILE_FLAGS([-Wall -Wextra -pedantic], [PKG_CFLAGS], [-Werror])
     AX_APPEND_COMPILE_FLAGS([-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict], [PKG_CFLAGS], [-Werror])
     AX_APPEND_COMPILE_FLAGS([-Wnull-dereference -Wjump-misses-init -Wdouble-promotion -Wshadow], [PKG_CFLAGS], [-Werror])
     AX_APPEND_COMPILE_FLAGS([-Wformat=2 -Wmisleading-indentation], [PKG_CFLAGS], [-Werror])])
  ])

### end of file
# Local Variables:
# mode: autoconf
# End:
