#include <iostream>
#include <string>
#include "client.h"

using namespace std;
// This is to be run in a format of bin.out myip peerip myport peerport
bool valid_input(string arg1, string arg2, string arg3, string arg4)
{
  if ((isdigit(stoi(arg1)) != 0) || (isdigit(stoi(arg2)) != 0) || (isdigit(stoi(arg3)) != 0)  || (isdigit(stoi(arg4)) != 0) )
  return false;
}
int main(char* argv[], int * argc)
{
  if (!valid_input(argv[1], argv[2], argv[3],argv[4]))
  {
    cout << " Wrong Format | Format is bin.out <myip> <peerip> <myport> <peerport>" << endl;
    return 0;
  }
  else
  {
    clientx thispc(argv[1], argv[2], stoi(argv[3]), stoi(argv[4]));
  }
}
