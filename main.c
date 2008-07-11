#include <stdio.h>
#include <stdlib.h>
#include <libhac.h>

int main(int argc, char *argv[])
{
	int foo;

	if(argc == 5)
		setRgbValues(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]));
	else if(argc == 1)
		rgbBlink(foo,foo);
	else
	{
		printf("Usage: ./main HOST RGB_DEST RED GREEN BLUE SMOOTHNESS\n");
		exit(-1);
	}

	return 0;
}
