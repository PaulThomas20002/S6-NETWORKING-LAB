#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main()
{
int socketid,b,newsocket,len;
char recline[100];
struct sockaddr_in serveraddr, clientaddr;
bzero(&serveraddr, sizeof(serveraddr));

//Creating the socket
socketid=socket(AF_INET,SOCK_STREAM,0);
if(socketid<0)
printf("Socket cannot be created \n");
else
printf("Socket created");

//Setting parameters of the socket

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3000);
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);

//Binding Socket

b=bind(socketid,(struct sockaddr*)&serveraddr, sizeof(serveraddr));
if(b<0)
printf("Cannot bind socket");
else
printf("\n Socket binded successfully");
listen(socketid,10);
len=sizeof(clientaddr);
newsocket=accept(socketid,(struct sockaddr*)&clientaddr,&len);
printf("Accepted");
}
