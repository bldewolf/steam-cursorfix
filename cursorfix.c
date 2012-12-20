#include <X11/Xcursor/Xcursor.h>
#ifndef NDEBUG
#include <stdio.h>
#endif

int XDefineCursor(Display *display, Window w, Cursor cursor) {
#ifndef NDEBUG
	puts("Preventing cursor setting");
#endif
	return 0;
}
