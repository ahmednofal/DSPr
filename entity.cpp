#include <socket.h>
#include "utils.c++"
#include <netinet/in.h>
#include <pthread.h>
#include "entity.h"
entity::entity(string myip, string peerip, int myPort,	int peerPort)
{
  myAddress = myip;
  myPort = myPort;
  peerAddress = peerip;
  peerPort = peerPort;
  entsock = new udpsocket(string myAddress,int myPort,string peerAddress,int peerPort);


}
