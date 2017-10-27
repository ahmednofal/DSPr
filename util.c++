#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
extern "C" {
	char * inet_ntoa(struct in_addr);
}

void setBroadcast(int s)
{
	int arg;
#ifdef SO_BROADCAST
	arg =1;
	if(setsockopt(s, SOL_SOCKET, SO_BROADCAST, &arg, sizeof(arg)) <0){
		perror("setsockopt SO_BROADCAST---");
		exit(-1);
	}
#endif
}
void makeLocalSA(struct sockaddr_in *sa)
{
	sa->sin_family = AF_INET;
	sa->sin_port = htons(0);
	sa-> sin_addr.s_addr = htonl(INADDR_ANY);
}
void makeDestSA(struct sockaddr_in * sa, char *hostname, int port)
{
	 struct hostent *host;
	 sa->sin_family = AF_INET;
	 if((host = gethostbyname(hostname))== NULL){
		 printf("Unknown host name\n");
		 exit(-1);
	 }
	 sa-> sin_addr = *(struct in_addr *) (host->h_addr);
	 sa->sin_port = htons(port);
}
void printSA(struct sockaddr_in sa)
{
	printf("sa = %d, %s, %d\n", sa.sin_family,
			inet_ntoa(sa.sin_addr), ntohs(sa.sin_port));
}
void sender(char *message1, char *message2, char *machine, int port)
{
	 int s, n;
	 struct sockaddr_in mySocketAddress, yourSocketAddress;
	 if(( s = socket(AF_INET, SOCK_DGRAM, 0))<0) {
		 perror("socket failed");
		 return;
	 }
	 setBroadcast(s);
	  /*see Section 2.7 */
	 makeLocalSA(&mySocketAddress);
	 if( bind(s, &mySocketAddress, sizeof(struct sockaddr_in))!= 0){
		 perror("Bind failed\n");
		 close (s);
		 return;
	 }
	 makeDestSA(&yourSocketAddress,machine, port);
	 if( (n = sendto(s, message1, strlen(message1), 0, &yourSocketAddress,
					 sizeof(struct sockaddr_in))) < 0) perror("Send 2 failed\n");
	 if( (n = sendto(s, message2, strlen(message2), 0, &yourSocketAddress,
					 sizeof(struct sockaddr_in))) < 0) perror("Send 2 failed\n");
	 close(s);
}

/*receive two messages through port given as argument*/
void receiver(int port)
{
	char message1[SIZE], message2[SIZE];
	struct sockaddr_in mySocketAddress, aSocketAddress;
	int s,aLength, n;
	if((s = socket(AF_INET, SOCK_DGRAM, 0))<0) {
		perror("socket failed");
		return;
	}
	makeReceiverSA(&mySocketAddress, port);
	if( bind(s, &mySocketAddress, sizeof(struct sockaddr_in))!= 0){
		perror("Bind failed\n");
		close(s);
		return;
	}
	aLength = sizeof(aSocketAddress);
	aSocketAddress.sin_family = AF_INET; /* note that this is needed */
	if((n = recvfrom(s, message1, SIZE, 0, &aSocketAddress, &aLength))<0)
		perror("Receive 1") ;
}
if((n = recvfrom(s, message2, SIZE, 0, &aSocketAddress, &aLength))<0)
	perror("Receive 2");
	}
close(s);
}
void makeReceiverSA(struct sockaddr_in *sa, int port)
{
	sa->sin_family = AF_INET;
	sa->sin_port = htons(port);
	sa-> sin_addr.s_addr = htonl(INADDR_ANY);
}
void main()
{
sender(8080);
receiver(8081);

}

