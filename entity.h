#include <socket.h>
#include "utils.c++"
#include <netinet/in.h>
#include <pthread.h>
#include "udpsocket.h"
#include <string>

class entity{
private:
udpsocket * entsock;
string myAddress;
int myPort;
string peerAddress;
int peerPort;
public:
  entity(string myip, string peerip, int myPort,	int peerPort);
  // setSockInfo(string myip, string peerip, int myPort,	int peerPort);
  udpsocket sock ();

  ~entity();

};

// DoOperation(Message * message, )
