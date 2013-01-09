#define _GNU_SOURCE

#include <dlfcn.h>
#include <X11/Xcursor/Xcursor.h>
#include <stdio.h>
#include <X11/cursorfont.h>

Cursor default_cursor = -1;

Cursor XCreateFontCursor(Display *display, unsigned int shape) {
	Cursor cursor;
	Cursor (*orig_XCreateFontCursor)(Display *display, unsigned int shape);

	orig_XCreateFontCursor = dlsym(RTLD_NEXT, "XCreateFontCursor");
	cursor = orig_XCreateFontCursor(display, shape);

	if(shape == XC_arrow)
		default_cursor = cursor;

//	printf("Set shape %d to XID %d\n", shape, cursor);
	return cursor;
}


int XDefineCursor(Display *display, Window w, Cursor cursor) {
	int (*orig_XDefineCursor)(Display *display, Window w, Cursor cursor);
	Window root;
	root = DefaultRootWindow(display);
	if(w == root) {
		// Yay, this never happens anymore
		puts("Trying to set cursor for root window");
	} else {
//		printf("Cursor id %d\n", cursor);
		if(cursor != default_cursor) {
//			puts("Setting cursor for non-root window");
			orig_XDefineCursor = dlsym(RTLD_NEXT, "XDefineCursor");
			return orig_XDefineCursor(display, w, cursor);
		} else {
//			puts("Unsetting cursor for non-root window");
			XUndefineCursor(display, w);
		}
	}
	return 0;
}
