LDFLAGS=-lhac
CFLAGS=-I../libhac
main: main.o

clean:
	rm *.o main
