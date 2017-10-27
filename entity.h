#include <sys/socket.h>
#include "utils.c++"
#include <netinet/in.h>
#include <pthread.h>
#include "udpsocket.h"
#include <string>
using namespace std;
class entity{
private:
udpsocket * entsock;
string myAddress;
int myPort;
string peerAddress;
int peerPort;
public:
  entity(string myip, string peerip, int myPort,	int peerPort);
  udpsocket * getentsock();
  int getMyPort();
  int getPeerPort();
  string getmyAddress();
  string getpeerAddress();


  ~entity();

};

// DoOperation(Message * message, )
