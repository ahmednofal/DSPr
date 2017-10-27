#ifndef CLIENT_H
#define CLIENT_H
#include "entity.h"
class Client:public entity
{
	public:
		//string myip, string peerip, int myPort,	int peerPort
		Client(string myip, string peerip, int myPort, int peerPort);
		Message * execute(Message * _message);
		~Client();
};
#endif // CLIENT_H
