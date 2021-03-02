.PHONY: all clean

all: libsem.a zadanie2.x powielacz.x prog.x

sem.o: sem.c sem.h
libsem.a: sem.o
zadanie2.x: zadanie2.c sem.h
powielacz.x: powielacz.c sem.h
prog.x: prog.c sem.h

libsem.a: sem.o
	ar rv libsem.a sem.o

sem.o: sem.c sem.h
	$(CC) $(CFLAGS) -c -o $@ $<

zadanie2.x: zadanie2.c sem.h
	gcc zadanie2.c -lpthread -o zadanie2.x -L. -lsem 

powielacz.x: powielacz.c sem.h
	gcc powielacz.c -lpthread -o powielacz.x -L. -lsem 

prog.x: prog.c sem.h
	gcc prog.c -lpthread -o prog.x -L. -lsem 


#laczy wszystkie .o w jeden plik wykonywalny
%.x: %.o 
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x *.a



