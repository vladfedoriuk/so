.PHONY: all clean

all: drzewo1.x

procinfo.o: procinfo.c procinfo.h
drzewo1.o: drzewo1.c procinfo.h
drzewo1.x: drzewo1.o procinfo.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x





