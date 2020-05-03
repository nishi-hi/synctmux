dnl                                               -*- Autoconf -*-
dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([synctmux], [1.0], [github.com/nishi-hi/synctmux])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_LANG(C++)
AC_SUBST([CPPFLAGS], ["${CPPFLAGS}"])
AC_SUBST([CXXFLAGS], ["${CXXFLAGS}"])
AC_SUBST([AM_CPPFLAGS], ["-I\$(top_srcdir)"])
AC_SUBST([AM_CXXFLAGS], ["-g -O3"])

dnl Macro definitions. ST means SyncTmux.
AC_DEFUN([ST_ARG_WITH_FILE], [AC_ARG_WITH([$1], AS_HELP_STRING([--with-$1@<:@=FILE@:>@], [$2]), [], [with_$1=no])])
AC_DEFUN([ST_CHECK_PROG], [
           AC_CHECK_PROG($1, $1, $1, no)
           AS_IF([test "x[$]$1" = xno], [AC_MSG_ERROR([$1 not found.])])
         ])

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_SED
AC_PROG_INSTALL
AC_PROG_MKDIR_P
ST_CHECK_PROG(bash)
ST_CHECK_PROG(ssh)
ST_CHECK_PROG(tput)
ST_CHECK_PROG(whoami)
ST_ARG_WITH_FILE([tmux], [specify tmux command (default is auto)])
AS_IF([test "x$with_tmux" = xno || test "x$with_tmux" = xyes], [AC_PATH_PROG(tmux, tmux, tmux, no)],
      [test "x$with_tmux" != xno && test "x$with_tmux" != xyes], [
       AS_IF([AS_EXECUTABLE_P([$with_tmux])], [tmux=$with_tmux], [AC_MSG_ERROR([check whether $with_tmux exists and it is executable.])])
      ])
AS_IF([test "x$tmux" = xno], [AC_MSG_ERROR([tmux not found. tmux >= 3.0 is needed.])])
AC_DEFUN([TMUX_VERSION_GOOD], [AC_MSG_NOTICE([tmux version $tmux_version is good.])])
AC_DEFUN([TMUX_VERSION_NO_GOOD], [AC_MSG_ERROR([tmux version $tmux_version is no good. version >= 3.0 is needed.])])
AS_VERSION_COMPARE(`$tmux -V | awk '{print $2}'`, 3.0, [TMUX_VERSION_NO_GOOD], [TMUX_VERSION_GOOD], [TMUX_VERSION_GOOD])
AC_SUBST(tmux)
AC_CANONICAL_HOST
AS_CASE([$host_os],
  [linux*], [
    AC_CHECK_PROG(xclip, xclip, xclip, no)
    AS_IF([test "x$xclip" = xno], [AC_MSG_ERROR([xclip not found.])])
    copy_to_clipboard="$xclip -se c -i"
  ],
  [darwin*], [
    AC_CHECK_PROG(pbcopy, pbcopy, pbcopy, no)
    AS_IF([test "x$pbcopy" = xno], [AC_MSG_ERROR([pbcopy not found.])])
    copy_to_clipboard="$pbcopy"
  ],
  [AC_MSG_ERROR(["OS $host_os is not supported."])]
)
AC_SUBST(copy_to_clipboard)

dnl Checks for libraries.

dnl Checks for header files.
AC_CHECK_HEADERS([iostream vector])

dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile src/synctmux.conf])
AC_CONFIG_FILES([src/synctmux], [chmod +x src/synctmux])
AC_OUTPUT
