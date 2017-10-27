#ifndef UDPSOCKET_H
#define UDPSOCKET_H
#include <netinet/in.h>
#include <pthread.h>
#include <string>

using namespace std;
class udpsocket
{
	protected:
	int sock;
	sockaddr_in mySA;
	sockaddr_in	peerSA;
	string myAddress;
	string peerAddress;
	int myPort;
	int peerPort;
	bool enabled;
	pthread_mutex_t mutex;
	public:
	udpsocket(string myAddress,int myPort,string peerAddress,int peerPort);
	int getsock();
	int getMyPort ();
	int getPeerPort ();
	void enable();
	void disable();
	bool isEnabled();
	void lock();
	void unlock();
	int getSocketHandler();
	~udpsocket();
};
#endif // UDPSOCKET_H
