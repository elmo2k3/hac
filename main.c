#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "main.h"

int main(int argc, char *argv[])
{
	struct sockaddr_in server,client;
	int client_sock, server_sock;
	unsigned char buf[BUF_SIZE];
	int recv_size;
	int send_size;
	unsigned char command;

	struct _rgbPacket rgbPacket;

	if(argc != 7)
	{
		printf("Usage: ./main HOST RGB_DEST RED GREEN BLUE SMOOTHNESS\n");
		exit(-1);
	}

	client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(client_sock < 0)
		printf("Client_sock konnte nicht erstellt werden\n");
	server.sin_family = AF_INET;
	server.sin_port = htons(HAD_PORT);
	inet_aton(argv[1], &server.sin_addr);
	
	rgbPacket.address = atoi(argv[2]);
	rgbPacket.red = atoi(argv[3]);
	rgbPacket.green = atoi(argv[4]);
	rgbPacket.blue = atoi(argv[5]);
	rgbPacket.smoothness = atoi(argv[6]);
	
	rgbPacket.count = 4;

	if(connect(client_sock, (struct sockaddr*)&server, sizeof(server)) != 0)
		printf("Konnte nicht verbinden\n");
	command = CMD_NETWORK_RGB;
	send(client_sock, &command, 1, 0);
	send_size = send(client_sock, &rgbPacket, sizeof(rgbPacket), 0);

	close(client_sock);

	return 0;
}
