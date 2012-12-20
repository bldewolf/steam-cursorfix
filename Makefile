CC = gcc
CFLAGS = -fPIC -m32
CPPFLAGS = -DNDEBUG
LDFLAGS = -shared -m32
LDLIBS = 
OBJS = cursorfix.o
LIB = libcursorfix.so

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

run: $(LIB)
	LD_PRELOAD=${PWD}/$(LIB) steam


clean:
	$(RM) $(OBJS) $(LIB)

.PHONY: all run clean
