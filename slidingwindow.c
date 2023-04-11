#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int n;


struct frame{
	char ack;
	int data;
}fr[20];


int main(){
	int f,r=0;
	printf("enter the frame size:");
	scanf("%d",&f);
	printf("enter the window size:");
	scanf("%d",&n);
	if(n>f){
		n=f;
	}
	for(int i=0;i<f;i++){
		printf("\nsender  :enter the packets to the frame:");
		scanf("%d",&fr[i].data);		
		r=rand()%2+1;
		if (r==1){												// show 1 if the packet is received
			printf("receiver:the packet is received\n");
			fr[i].ack = "y";
		}
		else{
			printf("receiver:the packet is not received\n");	// show 0 if the packet is not received
			fr[i].ack = "n";
		}
	}
}
