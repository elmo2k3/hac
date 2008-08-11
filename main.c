#include <stdio.h>
#include <stdlib.h>
#include <libhac.h>

int main(int argc, char *argv[])
{
	uint8_t foo;
	float temperature;

	initLibHac("192.168.0.2");

	if(argc < 2)
	{
		printf("\nUsage: \
				%s blink     Flash red\n \
				%s sr NUM    Set relais to NUM\n \
				%s gr        Get relais status\n \
				%s tr NUM    Toggle relais\n \
				\n \
				%s sled RED GREEN BLUE SMOOTHNESS\n \
				%s gt MODUL SENSOR\n\n",
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0]);
		return 0;
	}

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

	else if(!strcmp(argv[1], "gt"))
	{
		getTemperature(atoi(argv[2]),
				atoi(argv[3]),
				&temperature);
		printf("\n%3.2f\n",temperature);
	}

	closeLibHac();

	return 0;
}
