.PHONY: all clean

all: zombie.x execute.x potomny.x

procinfo.o: procinfo.c procinfo.h
zombie.o: zombie.c procinfo.h
execute.o: execute.c potomny.c
potomny.o: potomny.c procinfo.h
potomny.x: potomny.o procinfo.o
zombie.x: zombie.o procinfo.o
execute.x: execute.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x





