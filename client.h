#ifndef CLIENT_H
#define CLIENT_H
#include "entity.h"
class Client:public entity
{
	public:
		Client(char * _hostname, int _port);
		Message * execute(Message * _message);
		~Client();
};
#endif // CLIENT_H
