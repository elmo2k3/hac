#ifndef __MAIN_H__
#define __MAIN_H__

#define HAD_PORT 4123
#define BUF_SIZE 1024
#define CMD_NETWORK_RGB 1

struct _rgbNetworkPacket
{
	int destination;
	int red;
	int green;
	int blue;
};

#endif

