EXECUTABLE = sllist_test
CC = c99
CFLAGS = -g -Wall -O0 -Iinclude `pkg-config --cflags glib-2.0`
LDLIBS = `pkg-config --libs glib-2.0`

headers = $(wildcard include/*.h)
lib_hdr = $(wildcard src/*.h)
lib_src = $(wildcard src/*.c)
test_hdr = $(wildcard src/*.h)
test_src = $(wildcard test/*unit.c)


$(EXECUTABLE): $(patsubst %.c, %.o, $(test_src)) $(patsubst %.c, %.o, $(lib_src))
	$(CC) $(CFLAGS) $(LDLIBS) $^ -o $@

clean:
	rm -f src/*.o test/*.o $(EXECUTABLE)

