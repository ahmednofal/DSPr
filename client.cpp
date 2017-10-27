#include "client.h"
#include "utils.c++"
#include <socket.h>
using namespace std;

Client::Client(char * _hostname, int _port)
{
	
}
Client::
Client::Message * execute ( Message* _message)
{


	_message.setMessageType(Request);
	udpSocket.sendto(int s , //message , //message_size , 0 ,struct sockaddr *to, int tolen)
	udpSocket.recvfrom(int s, //message, /message_size, 0, struct sockaddr * from, int *fromlen)



}
