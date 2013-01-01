#define _GNU_SOURCE

#include <dlfcn.h>
#include <X11/Xcursor/Xcursor.h>
#include <stdio.h>

int XDefineCursor(Display *display, Window w, Cursor cursor) {
	int (*orig_XDefineCursor)(Display *display, Window w, Cursor cursor);
	Window root;
//	printf("Preventing cursor setting\n");
	root = DefaultRootWindow(display);
	if(w == root) {
		puts("Trying to set cursor for root window");
	} else {
		puts("Setting cursor for non-root window");
		orig_XDefineCursor = dlsym(RTLD_NEXT, "XDefineCursor");
		return orig_XDefineCursor(display, w, cursor);
	}
	return 0;
}
