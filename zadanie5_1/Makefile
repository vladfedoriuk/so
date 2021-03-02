.PHONY: all clean

all: procesy.x

procinfo.o: procinfo.c procinfo.h
procesy.o: procesy.c procinfo.h
procesy.x: procesy.o procinfo.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x





