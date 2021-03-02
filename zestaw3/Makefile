.PHONY: all clean

all: main.x

procinfo.o: procinfo.c procinfo.h
obsluga.o: obsluga.c procinfo.h
obsluga.x: obsluga.o procinfo.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#laczy wszystkie .o w jeden plik wykonywalny
%.x: %.o 
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x 



