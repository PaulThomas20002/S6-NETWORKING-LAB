#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


char buff[4096];
int MAX=60;

void main(){
	int sock_fd,n;
    struct sockaddr_in serv_addr;
    char send[MAX],recvline[MAX],s[MAX],name[MAX];
    
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd<0)
		printf("Cannot create socket\n");
	else
		printf("Socket created\n");	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(3000);


	connect(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	while(1){
		printf("\nEnter the source file name : \n");
	    scanf("%s",send);
	    
	    write(sock_fd,send,MAX);
	    if(strcmp(send,"exit")==0){
	    	exit(0);
	   	}
	    read(sock_fd,recvline,MAX);
	    
	    printf("%s",recvline);
	    
			
	}
    
    
    close(sock_fd);

    


}
