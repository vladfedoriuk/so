.PHONY: all clean

all: macierzysty.x potomny.x drzewo1.x drzewo2.x execute.x orphan.x zombie.x 

procinfo.o: procinfo.c procinfo.h
potomny.o: potomny.c procinfo.h
potomny.x: potomny.o procinfo.o
macierzysty.o: macierzysty.c procinfo.h
macierzysty.x: macierzysty.o procinfo.o
drzewo1.o: drzewo1.c procinfo.h
drzewo1.x:drzewo1.o procinfo.o
drzewo2.o: drzewo2.c procinfo.h
drzewo2.x:drzewo2.o procinfo.o
execute.o: execute.c procinfo.h
execute.x: execute.o procinfo.o
orphan.o: orphan.c procinfo.h
orphan.x: orphan.o procinfo.o
zombie.o: zombie.c
zombie.x: zombie.o


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x





