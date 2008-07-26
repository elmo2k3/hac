#include <stdio.h>
#include <stdlib.h>
#include <libhac.h>

int main(int argc, char *argv[])
{
	uint8_t foo;

	if(argc < 2)
		return 0;

	if(!strcmp(argv[1],"blink"))
		rgbBlink(0,0);

	else if(!strcmp(argv[1],"sr"))
		setRelais(atoi(argv[2]));

	else if(!strcmp(argv[1],"gr"))
	{
		getRelaisState(&foo);
		printf("%d\n",foo);
	}
	
	else if(!strcmp(argv[1],"tr"))
		toggleRelais(atoi(argv[2]));

	else if(!strcmp(argv[1],"sled"))
	{
		setRgbValues(atoi(argv[2]),
				atoi(argv[3]),
				atoi(argv[4]),
				atoi(argv[5]));
	}


	return 0;
}
