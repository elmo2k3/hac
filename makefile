LDFLAGS=-lhac
CFLAGS=-I../libhac
main: main.o

clean:
	rm *.o main

install: main
	cp main /usr/bin/hac
