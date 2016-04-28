#ifndef PHP_SCRAW_H
#define PHP_SCRAW_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"
#include "Zend/zend_alloc.h"
#include "ext/standard/info.h"
#include "ext/standard/php_string.h"
#include "Zend/zend_interfaces.h"

extern zend_module_entry scraw_module_entry;
#define phpext_scraw_ptr &scraw_module_entry

#define PHP_SCRAW_VERSION "0.1.0" 

#ifdef PHP_WIN32
#	define PHP_SCRAW_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_SCRAW_API __attribute__ ((visibility("default")))
#else
#	define PHP_SCRAW_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(scraw);
PHP_MSHUTDOWN_FUNCTION(scraw);
PHP_RINIT_FUNCTION(scraw);
PHP_RSHUTDOWN_FUNCTION(scraw);
PHP_MINFO_FUNCTION(scraw);

ZEND_BEGIN_MODULE_GLOBALS(scraw)
	char *scraw_var_name;
ZEND_END_MODULE_GLOBALS(scraw)

extern ZEND_DECLARE_MODULE_GLOBALS(scraw);

#ifdef ZTS
#define SCRAW_G(v) TSRMG(scraw_globals_id, zend_scraw_globals *, v)
#else
#define SCRAW_G(v) (scraw_globals.v)
#endif

#define SCRAW_STARTUP_FUNCTION(module)   	ZEND_MINIT_FUNCTION(scraw_##module)
#define SCRAW_STARTUP(module)	 		  	ZEND_MODULE_STARTUP_N(scraw_##module)(INIT_FUNC_ARGS_PASSTHRU)

#define DEBUG 0
#define S_PRINT if(DEBUG) php_printf

#define SEE_ZVAL(name,zp) php_printf("\nBEGIN SEE ZVAL %s \n",name); zend_print_zval_r(zp,0 TSRMLS_CC); php_printf("END SEE ZVAL %s \n",name);


#define SCRAW_END(number) exit(number)

#endif
