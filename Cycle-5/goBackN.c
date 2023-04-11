#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define W 4 // window size
#define N 10 // number of frames

void delay(int sec) {
    int ms = 1000000 * sec;
    usleep(ms);
}

int main() {
    int frames[N], sent_ack = -1, received_ack = -1;
    int window_start = 0, window_end = W - 1;
    
    printf("\n\nImplementing Go-Back-N ARQ Protocol\n\n");
    printf("Number of frames to be transmitted: %d\n", N);
    printf("Window size: %d\n", W);
    
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
                delay(1);
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
    return 0;
}
