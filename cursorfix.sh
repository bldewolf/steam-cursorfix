#!/bin/sh

if ! test -f libcursorfix.so; then
	gcc -shared -o libcursorfix.so cursorfix.c -ldl -fPIC -m32 || exit 1
fi

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$(pwd)"

LD_PRELOAD=libcursorfix.so steam
