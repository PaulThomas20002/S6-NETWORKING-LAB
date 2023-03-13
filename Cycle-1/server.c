#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

void main(){
        int sock_id, bind_v, newSocket,length;
        char recline[100], sendline[100];
        
        //builtin struct header
        struct sockaddr_in ser_addr, cli_addr;
        
        //clears - bzero
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
        ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);   // htonl - host to network long byte order,, INADDR_ANY- local host address
        
        //bind
        bind_v = bind(sock_id, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
        
        if(bind_v<0)
                printf("Cannot Bind socket");
        else
                printf("Success :: Bind socket\n");
                
       //listen
       
       listen(sock_id,10);

       length = sizeof(cli_addr);
       
       //accept
       newSocket = accept(sock_id, (struct sockaddr*)&cli_addr,&length);
       
       printf("Accepted :: success\n");
       
       bzero( recline, 100);
       bzero( sendline, 100);
       
        while(1){
                printf("The message from client : ");
                read(newSocket,recline,100);
                puts(recline);
                //bzero( sendline, 100);
                
                printf("The message from server :");
                gets(sendline);
                write(newSocket,sendline,sizeof(sendline));
                
                if (strcmp (recline, "quit") == 0|| strcmp (sendline, "quit") == 0)
                exit(0);
         
        }
        close(sock_id);

}
