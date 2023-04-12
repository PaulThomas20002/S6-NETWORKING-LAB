#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void main(){
        int sock_id, bind_v, newSocket,length;
        char sendline[100], recline[100];
               
        struct sockaddr_in ser_addr, cli_addr;
        
        bzero(&ser_addr, sizeof(ser_addr));
             
        sock_id = socket(AF_INET, SOCK_DGRAM, 0);
        
        if(sock_id < 0){
                printf("Socket cannot be created\n");
        }
        else{
                printf("Socket Created\n");
        }
        
        ser_addr.sin_family = AF_INET;
        ser_addr.sin_port = htons (3001);  
        //        ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
        ser_addr.sin_addr.s_addr = inet_addr("10.0.4.23");
        if(connect (sock_id,(struct sockaddr *)&ser_addr,sizeof(ser_addr)) < 0 )
                printf("Client Connected :: Failed\n");

        
        
        bzero( sendline, 100);
        bzero( recline, 100);
        do{
        
        printf("Message to server : ");
        gets(sendline);   
        
        sendto(sock_id, sendline, 1000, 0, (struct sockaddr*)NULL, sizeof(ser_addr)); 

         if(strcmp(sendline, "quit")== 0){
                exit(0);
        }
        
        printf("Message from server : ");
        recvfrom(sock_id, recline, sizeof(recline), 0, (struct sockaddr*)NULL, NULL);
        if(strcmp(recline, "quit")== 0){
                exit(0);
        }
        puts(recline);
        }while (strcmp(recline, "quit") || strcmp(sendline, "quit") != 0);
       
       
        close(sock_id);
}
