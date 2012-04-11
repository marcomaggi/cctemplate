# acinclude.m4 --
#

dnl page
AC_DEFUN([CCTEMPLATE_CHECK_PAGESIZE],
  [AC_CACHE_CHECK([page size],
     [cctemplate_cv_pagesize],
     [AC_COMPUTE_INT([cctemplate_cv_pagesize],[sysconf(_SC_PAGESIZE)],[
       #include <unistd.h>
     ],[cctemplate_cv_pagesize=4096])])])

dnl CCTEMPLATE_CHECK_PAGESHIFT($pagesize)
dnl
dnl Determine  the number  of bits  to  right-shift a  pointer value  to
dnl obtain  the index  of  the page  (of  size CCG_PAGESIZE)  it is  in.
dnl Defaults to 12 which is the value for a page size of 4096.
dnl
dnl The test assumes that the page size is an exact power of 2.
dnl
AC_DEFUN([CCTEMPLATE_CHECK_PAGESHIFT],
  [AC_CACHE_CHECK([page shift bit count],
     [cctemplate_cv_pageshift],
     [AC_RUN_IFELSE([AC_LANG_SOURCE([
        int main (void)
        {
           int count=0;
	   int roller=$1 - 1;
           FILE *f = fopen ("conftest.val", "w");
           while (roller) {
             ++count;
	     roller >>= 1;
           }
           fprintf(f, "%d", count);
           return ferror (f) || fclose (f) != 0;
        }])],
        [cctemplate_cv_pageshift=`cat conftest.val`],
        [cctemplate_cv_pageshift=12])
      rm -f conftest.val])])])


### end of file
