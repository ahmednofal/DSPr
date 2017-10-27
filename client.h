#ifndef CLIENT_H
#define CLIENT_H
#include "entity.h"
#include "utils.c++"
#include <sys/socket.h>
#include <string>

class clientx:public entity
{
	public:
		clientx(string myip, string peerip, int myPort, int peerPort);
		void DoOperation(string message);
		~clientx();
};
#endif // CLIENT_H
