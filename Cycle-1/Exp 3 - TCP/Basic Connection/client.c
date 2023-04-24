#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
void main()
{
int socketid,len;
char sendline[100];
struct sockaddr_in serveraddr, clientaddr;
bzero(&serveraddr, sizeof(serveraddr));

//Creating a socket
socketid=socket(AF_INET,SOCK_STREAM,0);
if(socketid<0)
printf("\nSocket cannot be created");
else
printf("\nSocket created");

//Setting parameters of socket

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3000);
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);


//Connecting to server
connect(socketid,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
printf("\n Client Connected\n");
}
