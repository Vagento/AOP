/*
  +----------------------------------------------------------------------+
  | AOP PHP extension                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2022 Valentin Wotschel                                 |
  +----------------------------------------------------------------------+
  | Permission is hereby granted, free of charge, to any person          |
  | obtaining a copy of this software and associated documentation files |
  | (the "Software"), to deal in the Software without restriction,       |
  | including without limitation the rights to use, copy, modify, merge, |
  | publish, distribute, sublicense, and/or sell copies of the Software, |
  | and to permit persons to whom the Software is furnished to do so,    |
  | subject to the following conditions:                                 |
  |                                                                      |
  | The above copyright notice and this permission notice shall be       |
  | included in all copies or substantial portions of the Software.      |
  |                                                                      |
  | THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      |
  | EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   |
  | MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND                |
  | NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  |
  | BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   |
  | ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN    |
  | CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE     |
  | SOFTWARE.                                                            |
  +----------------------------------------------------------------------+
  | Author: Valentin Wotschel <wotschel.valentin@googlemail.com>         |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <php.h>
#include <zend_API.h>
#include <zend_exceptions.h>
#include <zend_extensions.h>
#include <ext/standard/info.h>

#include "php_aop.h"

#ifdef COMPILE_DL_AOP
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(aop)
#endif

// Ignore unused
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedParameter"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

class AopPhpExtension
{
public:
    // Module startup
    static PHP_MINIT_FUNCTION(aop) {
        return SUCCESS;
    }

    // Module shutdown
    static PHP_MSHUTDOWN_FUNCTION(aop) {
        return SUCCESS;
    }

    // Request startup
    static PHP_RINIT_FUNCTION(aop) {
        return SUCCESS;
    }

    // Request shutdown
    static PHP_RSHUTDOWN_FUNCTION(aop) {
        return SUCCESS;
    }

    // Module info
    static PHP_MINFO_FUNCTION(aop) {
        php_info_print_table_start();
        php_info_print_table_header(2, "AOP support", "enabled");
        php_info_print_table_end();
    }
};

// Add all functions here (Keep PHP_FE_END at the end)
static const zend_function_entry aop_functions[] = {
    PHP_FE_END
};

class AopZendExtension
{
public:
    // Module startup
    static ZEND_DLEXPORT int aop_zend_startup(zend_extension *extension) {
        return zend_startup_module(&aop_module_entry);
    }
};

zend_module_entry aop_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_AOP_EXTNAME,
    aop_functions,
    AopPhpExtension::PHP_MINIT(aop),     // Module startup
    AopPhpExtension::PHP_MSHUTDOWN(aop), // Module shutdown
    AopPhpExtension::PHP_RINIT(aop),     // Request startup
    AopPhpExtension::PHP_RSHUTDOWN(aop), // Request shutdown
    AopPhpExtension::PHP_MINFO(aop),     // Module info
    PHP_AOP_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifndef ZEND_EXT_API
# define ZEND_EXT_API ZEND_DLEXPORT
#endif
ZEND_EXTENSION();

ZEND_DLEXPORT zend_extension zend_extension_entry = {
    PHP_AOP_EXTNAME,
    PHP_AOP_VERSION,
    PHP_AOP_AUTHOR,
    PHP_AOP_URL_FAQ,
    PHP_AOP_COPYRIGHT_SHORT,

    AopZendExtension::aop_zend_startup, // Startup
    nullptr,                            // Shutdown
    nullptr,                            // Activate
    nullptr,                            // Deactivate

    nullptr,                            // Message handler

    nullptr,                            // OP array handler

    nullptr,                            // Statement handler
    nullptr,                            // Function call begin handler
    nullptr,                            // Function call end handler

    nullptr,                            // Array constructor handler
    nullptr,                            // Array destructor handler

    STANDARD_ZEND_EXTENSION_PROPERTIES
};