.PHONY: all clean

all: libmsg.a server.x client.x


msg.o: msg.c msg.h
libmsg.a: msg.o
server.x: server.c msg.h
client.x: client.c msg.h

libmsg.a: msg.o
	ar rv libmsg.a msg.o

msg.o: msg.c msg.h
	$(CC) $(CFLAGS) -c -o $@ $<

client.x: client.c msg.h
	gcc client.c -lpthread -o client.x -L. -lmsg

server.x: server.c msg.h
	gcc server.c -lpthread -o server.x -L. -lmsg 

#laczy wszystkie .o w jeden plik wykonywalny
%.x: %.o 
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.o *.x *.a



