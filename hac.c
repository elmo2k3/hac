#include <stdio.h>
#include <stdlib.h>
#include <libhac.h>


int main(int argc, char *argv[])
{
	uint8_t foo;
	float temperature;
	
	char *server_ip = getenv("HAD_HOST");

	if(!server_ip)
		server_ip = "192.168.0.2";

	initLibHac(server_ip);
//	initLibHac("192.168.0.2");
	
	if(argc < 2)
	{
		printf("\nUsage: \
				%s blink     Flash red\n\n \
				%s sr NUM    Set relais to NUM\n \
				%s gr        Get relais status\n \
				%s tr NUM    Toggle relais\n \
				\n \
				%s sled      RED GREEN BLUE SMOOTHNESS\n \
				%s sledm     MODUL RED GREEN BLUE SMOOTHNESS\n \
				%s gt	     MODUL SENSOR\n \
				%s gv 	     MODUL\n \
				%s lt 	     TEXT LIFETIME  Send text to LED-Display\n \
				%s lcdoff    Set base-station lcd off\n \
				%s lcdon     Set base-station lcd on\n \
				%s ledmon    Set ledmatrix display on\n \
				%s ledmoff   Set ledmatrix display off\n \
				%s scrobon   Set scrobbler on\n \
				%s scroboff  Set scrobbler off\n \
				\n",
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0],
				argv[0]);
		printf("Using host %s\n",server_ip);
		return 0;
	}

	if(!strcmp(argv[1],"blink"))
		rgbBlink(0,0);

	else if(!strcmp(argv[1],"sr"))
		setRelais(atoi(argv[2]));

	else if(!strcmp(argv[1],"gr"))
	{
		struct _hadState hadState;
		getHadState(&hadState);
		printf("%d\n",hadState.relais_state);
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
	else if(!strcmp(argv[1], "gv"))
	{
		getVoltage(atoi(argv[2]),
				&temperature);
		printf("\n%3.3f\n",temperature);
	}
	else if(!strcmp(argv[1], "sledm"))
	{
		setRgbValueModul(atoi(argv[2]),
				atoi(argv[3]),
				atoi(argv[4]),
				atoi(argv[5]),
				atoi(argv[6]));
	}
	else if(!strcmp(argv[1], "lt"))
	{
		ledSendText(argv[2],0,0,atoi(argv[3]));
	}
	else if(!strcmp(argv[1], "lcdoff"))
	{
		setBaseLcdOff();
	}
	else if(!strcmp(argv[1], "lcdon"))
	{
		setBaseLcdOn();
	}
	else if(!strcmp(argv[1], "ledmon"))
	{
		setLedmatrixOn();
	}
	else if(!strcmp(argv[1], "ledmoff"))
	{
		setLedmatrixOff();
	}
	else if(!strcmp(argv[1], "scrobon"))
	{
		setScrobblerOn();
	}
	else if(!strcmp(argv[1], "scroboff"))
	{
		setScrobblerOff();
	}

	closeLibHac();

	return 0;
}
