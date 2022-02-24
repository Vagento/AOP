dnl $Id$
dnl config.m4 extension AOP

sinclude(./autoconf/pecl.m4)
sinclude(./autoconf/php-executable.m4)

PECL_INIT([aop])

PHP_ARG_ENABLE([AOP],
    [whether to enable AOP support],
    [AS_HELP_STRING([--enable-AOP],
        [Enable AOP support])], [yes], [yes])

if test "$PHP_AOP" != "no"; then
    AC_DEFINE(HAVE_AOP, 1, [whether AOP is enabled])
    PHP_NEW_EXTENSION(aop, aop.c, $ext_shared)

    PHP_ADD_MAKEFILE_FRAGMENT
    PHP_INSTALL_HEADERS([ext/aop], [php_aop.h])
fi