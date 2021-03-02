.PHONY: all clean

all: main.x

procinfo.o: procinfo.c procinfo.h
main.o: main.c procinfo.h
main.x: main.o procinfo.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#laczy wszystkie .o w jeden plik wykonywalny
%.x: %.o 
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x 





