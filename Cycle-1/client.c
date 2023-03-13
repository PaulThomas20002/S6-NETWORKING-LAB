#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

void main(){
        int sock_id, bind_v, newSocket,length;
        char sendline[100],recline[100];
        //builtin struct header
        struct sockaddr_in ser_addr, cli_addr;
        
        //clears struct variable - bzero 
        bzero(&ser_addr, sizeof(ser_addr));
        //create socket     
        sock_id = socket(AF_INET, SOCK_STREAM, 0);
        
        if(sock_id < 0){
                printf("Socket cannot be created\n");
        }
        else{
                printf("Socket Created\n");
        }
        
        ser_addr.sin_family = AF_INET;  // AF_INET -IPv4 type
        ser_addr.sin_port = htons (3000);   // htons - byte order like big-o endian
        ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);   // htonl - host to network long byte order
        
        //connect
        connect(sock_id,(struct sockaddr *)&ser_addr,sizeof(ser_addr));
        
        printf("Client Connected :: success\n");
        
        //sending message to server;
        
        bzero( sendline, 100);
        bzero( recline, 100);
        
        while(1){
                printf("The message from client : ");
                gets(sendline);
                write(sock_id,sendline,sizeof(sendline));
                
                printf("The message from server");
                read(sock_id,recline,100);
                puts(recline);
                bzero( sendline, 100);
        }
        close(sock_id);
}
