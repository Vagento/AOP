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
    PHP_REQUIRE_CXX()
    PHP_ADD_LIBRARY_WITH_PATH(stdc++, "", AOP_SHARED_LIBADD)
    PHP_SUBST(AOP_SHARED_LIBADD)

    CXXFLAGS="$CXXFLAGS -std=c++11"

    AC_DEFINE(HAVE_AOP, 1, [whether AOP is enabled])
    PHP_NEW_EXTENSION(aop, aop.cpp, $ext_shared)

    PHP_ADD_MAKEFILE_FRAGMENT
    PHP_INSTALL_HEADERS([aop], [php_aop.h])
fi