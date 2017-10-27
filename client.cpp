#include <iostream>
#include "client.h"
#include <string>

using namespace std;

clientx::clientx(string myip, string peerip, int myPort, int peerPort) : entity(myip, peerip, myPort, peerPort)
{
	string input;
	while(1)
	{
		cout << "\n\t Message ==> " << endl;
		cin >> input;
		DoOperation(input);
	}

}
void clientx::DoOperation(string message)
{
	if (sendto(getentsock()->getsock(), message, message.length(), 0, &peerSA, sizeof(struct sockaddr_in)) < 0)
	{
		cout << " \n\tFailed to send a message\t .... Exiting >>>> TRY AGAIN " << endl;
		return ;
	}
}
clientx::~clientx()
{

}
// Client::Message * execute ( Message* _message)
// {
//
//
// 	_message.setMessageType(Request);
// 	udpSocket.sendto(int s , //message , //message_size , 0 ,struct sockaddr *to, int tolen)
// 	udpSocket.recvfrom(int s, //message, /message_size, 0, struct sockaddr * from, int *fromlen)
//
//
//
// }
