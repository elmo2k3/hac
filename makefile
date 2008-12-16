LDFLAGS=-lhac
CFLAGS=-I../libhac

hac: hac.o

clean:
	$(RM) *.o main

install: hac
	cp hac /usr/bin/hac
