LDFLAGS=`pkg-config libhac --libs` -lssl
CFLAGS=`pkg-config libhac --cflags`

hac: hac.o

clean:
	$(RM) *.o main

install: hac
	cp hac /usr/bin/hac
