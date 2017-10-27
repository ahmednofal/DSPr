#include <udpsocket.h>
#include "utils.cpp"
#include <string>
using namespace std;
udpsocket::udpsocket(string myipaddress,int myport,string peeripaddress,int peerport)
{
	/*
	string myIPAddress;
	int sock;
	sockaddr_in mySA;
	sockaddr_in	peerSA;
	string peerIPAddress;
	int myPort;
	int peerPort;
*/
	peerIPAddress = peeraddress;
	myIPAddress = myaddress;
	myPort = myport;
	peerPort = peerport;

	if(( sock = socket(AF_INET, SOCK_DGRAM, 0))<0) {
		perror("socket  failed");
		return;
	}
		setBroadcast(sock);

	makeLocalSA(mySA.c_str());
	if(bind(sock, &mySA, sizeof(struct sockaddr_in))!= 0)
	{
	perror("Bind  failed\n");
	close (socket);
	return;
	}
	// The interpretation of makeDestSA expect a string of the host name
	makeDestSA(&peerSA,hostname, peerPort);

}
int udpsocket::getsock(){
	return sock;
}
