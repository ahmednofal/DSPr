#ifndef UDPSOCKET_H
#define UDPSOCKET_H
#include <netinet/in.h>
#include <pthread.h>

class udpsocket
{
	protected:
	int sock;
	sockaddr_in mySAddr;
	sockaddr_in	peerSAddr;
	string myAddress;
	string peerAddress;
	int myPort;
	int peerPort;
	bool enabled;
	pthread_mutex_t mutex;
	public:
	udpsocket(string myAddress,int myPort,string peerAddress,int peerPort);
	int getMyPort ();
	int getPeerPort ();
	void enable();
	void disable();
	bool isEnabled();
	void lock();
	void unlock();
	int getSocketHandler();
	~UDPSocket ( );
};
#endif // UDPSOCKET_H
