.PHONY: all clean

all: drzewo2.x

procinfo.o: procinfo.c procinfo.h
drzewo2.o: drzewo2.c procinfo.h
drzewo2.x: drzewo2.o procinfo.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x





