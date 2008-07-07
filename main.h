#ifndef __MAIN_H__
#define __MAIN_H__

#define HAD_PORT 4123
#define BUF_SIZE 1024
#define CMD_NETWORK_RGB 1

struct _rgbPacket
{
	unsigned char address;
	unsigned char count;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char smoothness;
};

#endif

