#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

int r,n;
struct frame{
	int data;
	char ack;
	char wait;	
}frm[25], frame[25];

void selective(){
	for(int i=1;i<=n;i++){
		printf("Enter the value of frame %d : ",i);
		scanf("%d",&frm[i].data);
		frm[i].ack='y';
		//rand();	
		r=3;
	}
	int lc=1;
	int w_size;
	printf("Enter The Window Size: ");
	scanf("%d",&w_size);
	frm[r].ack='n';
	end:
	for(int i = lc; i <=(n - w_size) + 1;)  {   
        for(int j = i; j < i + w_size; j++){  
            if(frm[j].wait!='n'){
				printf("Sending value %d\n",frm[j].data);
			}
			frm[j].wait='y';
            
           
        }  
		sleep(1);
		int count=0;
		for(int j = i; j < i + w_size; j++){
			if(frm[j].ack=='y'){
				if(j==i)
				count++;
				printf("Packet received with data : %d\n",frm[j].data);
				
            }
			else{
				printf("Packet Lost %d\n",frm[j].data);
				goto skip;
			}
			
			if(count>0){
				lc++;
				printf("skipping\n");
				
				goto end;
			}
			}
		}
		skip:

		for(int i = lc; i <=n;i++){
			if(frm[i].ack!='n'){
				printf("Sending value %d\n",frm[i].data);
			}
			if(frm[i].ack=='y'){
				printf("Packet received with data : %d\n",frm[i].data);
				
            }
			else{
				frm[i].ack='y';
				printf("Packet Lost %d\n",frm[i].data);
			}
			if (i==lc+(w_size-1)){
				printf("Packet received with data : %d\n",frm[r].data);
			}
		}

		
    }  


void goback(){
    int frames[25], sent_ack = -1, received_ack = -1;
    int window_start = 0, window_end;
    int N, W ;
    
    printf("Number of frames to be transmitted : ");
    scanf("%d", &N);
    printf("Window size : ");
    scanf("%d", &W);
    window_end = W - 1;

    // initialize frames to be transmitted
    for(int i = 0; i < N; i++) {
        frames[i] = i;
    }
    
    // simulate frame transmission
    while(sent_ack < N - 1) {
        // send frames within window
        for(int i = window_start; i <= window_end; i++) {
            if(sent_ack < i) {
                printf("\nSending frame %d", frames[i]);
                sleep(1);
                printf("\nFrame %d has been sent", frames[i]);
            }
        }
        
        // receive acknowledgement
        printf("\nEnter acknowledgement: ");
        scanf("%d", &received_ack);
        
        // check if acknowledgement is valid
        if(received_ack > sent_ack && received_ack <= window_end) {
            printf("\nAcknowledgement received for frame %d", received_ack);
            sent_ack = received_ack;
            window_start = sent_ack + 1;
            window_end = window_start + W - 1;
            if(window_end >= N) {
                window_end = N - 1;
            }
        }
        else {
            printf("\nInvalid acknowledgement received");
        }
    }
    
    printf("\n\nAll frames have been transmitted successfully\n");

}

void stopnwait(){
    int i, size;
    printf("\nNo. of packets to be sent:");
    scanf("%d", & n);
    for (i = 1; i <= n; i++) {
        printf("\nData for packets[%d] : ", i);
        scanf("%d", &frame[i].data);
        frame[i].ack = 'y';
        printf("Packet Sent\n Waiting for acknowledgement\n");
	    printf("\n");
	    sleep(1);
    
    // rand();
    //r = rand() % n;
    r = 3;
    //printf("random = %d", r);
    frame[r].ack = 'n';
 
    sleep(1);

    if (frame[i].ack == 'y'){
    printf("\nReceived data of packet %d is %d", i, frame[i].data);
    }
    else {
        
        printf("Packet Lost \nWait for infinite time ...\nProgram aborting ...");
        sleep(2);
        exit(0);
    }

}
}
int main(){

  int opt;
  do{

    printf("\n\n1.Selective repeat ARQ\n2.Goback ARQ\n3.Stop and Wait \n4.Exit");
    printf("\nOption : ");
    scanf("%d", &opt);
    /*rand();	
	r=rand()%n;*/
    
    switch (opt){

        case 1:      printf("Enter the no of Frames : ");
	                 scanf("%d",&n);
                     selective();      break;
        case 2:      goback();         break;
        case 3:      stopnwait();      break;
        case 4:      exit(0);          break;
        
    }
  } while (opt >= 4);

}
