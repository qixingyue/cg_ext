PHP_ARG_ENABLE(scraw, whether to enable scraw support,
Make sure that the comment is aligned:
[  --enable-scraw           Enable scraw support])


if test -z "$PHP_DEBUG" ; then
	AC_ARG_ENABLE(debug,
		[--enable-debug compile with debugging system],
		[PHP_DEBUG=$enableval],[PHP_DEBUG=no]
	)
fi

if test "$PHP_SCRAW" != "no"; then
PHP_NEW_EXTENSION(scraw, scraw.c \
		items/func.c \
		, $ext_shared)
	PHP_ADD_BUILD_DIR([$ext_builddir/items])
fi
