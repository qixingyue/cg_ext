#ifndef PHP_FUNC_SCRAW_H
#define PHP_FUNC_SCRAW_H

#include "php.h"
#include "php_scraw.h"

PHP_FUNCTION(simpleTest);

#define SCRAW_FUNCS \
PHP_FE(simpleTest,  NULL) 

#endif
