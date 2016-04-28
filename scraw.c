#include "php_scraw.h"
#include "little_items.h"

ZEND_DECLARE_MODULE_GLOBALS(scraw)

static int le_scraw;

const zend_function_entry scraw_functions[] = {
	SCRAW_FUNCS
	PHP_FE_END
};

#ifdef COMPILE_DL_SCRAW
ZEND_GET_MODULE(scraw)
#endif

PHP_INI_BEGIN()
		STD_PHP_INI_ENTRY("scraw.scraw_var_name", "x_run_pool", PHP_INI_ALL, OnUpdateString, scraw_var_name, zend_scraw_globals, scraw_globals)
PHP_INI_END()

PHP_GINIT_FUNCTION(scraw){
	scraw_globals->scraw_var_name = "x_run_pool";
}

PHP_MINIT_FUNCTION(scraw) {
	REGISTER_INI_ENTRIES();
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(scraw)
{
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}

PHP_RINIT_FUNCTION(scraw)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(scraw)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(scraw)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "scraw support", "enabled");
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

zend_module_entry scraw_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"scraw",
	scraw_functions,
	PHP_MINIT(scraw),
	PHP_MSHUTDOWN(scraw),
	PHP_RINIT(scraw),	
	PHP_RSHUTDOWN(scraw),	
	PHP_MINFO(scraw),
	PHP_SCRAW_VERSION,
	PHP_MODULE_GLOBALS(scraw),
	PHP_GINIT(scraw),
	NULL,
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};


