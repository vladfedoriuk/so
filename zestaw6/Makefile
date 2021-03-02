.PHONY: all clean

all: libshm.so shm.o shmuse.x libsem.a sem.o creator.x producent.x konsument.x

shm.o: shm.c shm.h
libshm.o: shm.o
shmuse.o:shmuse.c libshm.so
shmuse.x:shmuse.c libshm.so
sem.o: sem.c sem.h
libsem.a: sem.o
creator.o:creator.c sem.h shm.h
creator.x: creator.o libsem.a libshm.so
konsument.o:konsument.c sem.h shm.h
producent.x: producent.o libsem.a libshm.so

libsem.a: sem.o
	ar rv libsem.a sem.o

sem.o: sem.c sem.h
	$(CC) $(CFLAGS) -c -o $@ $<

libshm.so: shm.o
	gcc -shared -o libshm.so shm.o

shm.o: shm.c shm.h
	gcc -c -O -fPIC shm.c

shmuse.x:shmuse.c libshm.so
	gcc shmuse.c -o shmuse.x -L. -lshm -lrt

creator.x:creator.c libshm.so libsem.a
	gcc creator.c -o creator.x -L. -lsem -lshm -lrt

konsument.x:konsument.c libshm.so libsem.a
	gcc konsument.c -o konsument.x -L. -lsem -lshm -lrt

producent.x:producent.c libshm.so libsem.a
	gcc producent.c -o producent.x -L. -lsem -lshm -lrt

#laczy wszystkie .o w jeden plik wykonywalny
%.x: %.o 
	$(CC) $(LDFLAGS) -o $@ $^ 

clean:
	$(RM) *.o *.x *.so
