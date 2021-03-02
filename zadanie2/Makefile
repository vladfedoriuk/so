.PHONY: all clean 

all: kopiuj.x

kopiuj.o: kopiuj.c
kopiuj.x: kopiuj.o 


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x
