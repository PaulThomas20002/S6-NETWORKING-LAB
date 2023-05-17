#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
        int sock_id, bind_v, newSocket,length;
        char recline[100], sendline[100];
        
        struct sockaddr_in ser_addr, cli_addr;
        
        
        bzero(&ser_addr, sizeof(ser_addr));     

        sock_id = socket(AF_INET, SOCK_DGRAM, 0); //Dgram is used in udp
        
        if(sock_id < 0){
                printf("Socket cannot be created\n");
        }
        else{
                printf("Socket Created\n");
        }
        
        ser_addr.sin_family = AF_INET; 
        ser_addr.sin_port = htons (3001);
        ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        

        bind_v = bind(sock_id, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
        
        if(bind_v<0)
                printf("Cannot Bind socket");
        else
                printf("Success :: Bind socket\n");
      
       length = sizeof(cli_addr);
       
       do{
        int n = recvfrom(sock_id, recline, sizeof(recline), 0, (struct sockaddr*)&cli_addr, &length); 
        recline[n] = '\0';
        printf("Message from client : ");
        puts(recline);
        printf("Message to client : ");
        gets(sendline);

        sendto(sock_id, sendline, 1000, 0, (struct sockaddr*)&cli_addr, sizeof(cli_addr));
        if(strcmp(recline, "exit")== 0){
                exit(0);
        }
        }while (strcmp(recline, "exit") || strcmp(sendline, "exit") != 0);
        close(sock_id);
}
