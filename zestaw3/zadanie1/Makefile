.PHONY: all clean

all: obsluga.x wysylaj.x grupa.x

procinfo.o: procinfo.c procinfo.h
obsluga.o: obsluga.c procinfo.h
obsluga.x: obsluga.o procinfo.o
wysylaj.o: wysylaj.c
wysylaj.x: wysylaj.o
grupa.o: grupa.c procinfo.c procinfo.h
grupa.x: grupa.o procinfo.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

#laczy wszystkie .o w jeden plik wykonywalny
%.x: %.o 
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x 





