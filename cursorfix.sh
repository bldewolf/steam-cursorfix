#!/bin/sh

if ! test -f libcursorfix.so; then
	gcc -shared -o libcursorfix.so cursorfix.c -ldl -fPIC -m32 || exit 1
fi

LD_PRELOAD=libcursorfix.so steam
