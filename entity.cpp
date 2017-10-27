#include "entity.h"
entity::entity(string myip, string peerip, int myPort,	int peerPort)
{
  myAddress = myip;
  myPort = myPort;
  peerAddress = peerip;
  peerPort = peerPort;
  entsock = new udpsocket(string myAddress,int myPort,string peerAddress,int peerPort);


}
udpsocket * entity::getentsock(){
  return entsock;
}
string entity::getpeerAddress(){
  return peerAddress;
}
string entity::getmyAddress()
{
  return myAddress;
}
int entity::getmyPort()
{
  return myPort;
}
int entity::getpeerPort()
{
  return peerPort;
}
