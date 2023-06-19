#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>



char buff[4096];
FILE *f1;
int MAX=60;

void main(){
	int sock_fd,newSock_fd,clength;
	struct sockaddr_in serv_addr,cli_addr;
	char t[5]="exit",str[60];
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
	if(sock_fd<0)
		printf("Cannot create socket\n");
	else
		printf("Socket created\n");	
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(3000);

	int b=bind(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	if(b<0)
		printf("Cannot Bind\n");
	else
		printf("Binded\n");
	listen(sock_fd,10);
	clength=sizeof(cli_addr);
	newSock_fd=accept(sock_fd,(struct sockaddr*)&cli_addr,&clength);
	close(sock_fd);
	
	do{
		read(newSock_fd,&str,60);

		if(strcmp(str,"exit")==0){
			close(newSock_fd);
			exit(0);
		}
		printf("\nClient msg\n\nFile Name: %s\n",str);
		f1=fopen(str,"r");
		if(f1==NULL){
			char err[100]="ERROR OCCURED! NO FILE FOUND";
			printf("\n%s\n",err);
			write(newSock_fd,err,60);
			continue;
		}
		else{
			
			while(fgets(buff,4096,f1)!=NULL){
				write(newSock_fd,buff,60);
				printf("\n");
			}
			fclose(f1);
		}
	}while(strcmp(str,"exit")!=0);	

	
	printf("File transfered\n\n");
}
