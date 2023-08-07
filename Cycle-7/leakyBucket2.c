#include <stdio.h>
#include <stdlib.h>

void main(){
    int storage = 0, input_pkt = 4, output_pkt = 1, bucket_size = 10;
    int packetnum = 4;
    
    printf("Enter the Packet Number : ");
    scanf("%d", &packetnum);
    
    printf("Enter the Output rate : ");
    scanf("%d", &output_pkt);
    
    printf("Enter the Bucket size : ");
    scanf("%d", &bucket_size);
    
    while ( packetnum!= 0){
        
        printf("\nEnter the incoming packet size : ");
        scanf("%d", &input_pkt);
        int size_left = bucket_size - storage;
        
        if ( input_pkt <= size_left ){
            storage = storage + input_pkt;
        }
        else {
            printf("\nPacket Loss : %d", input_pkt);
        }
        
        printf("\nstorage : %d  of bucket_size : %d", storage, bucket_size);
        storage = storage - output_pkt;
        
        packetnum--;
    }
    
    printf("\nStorage : %d  of bucket_size : %d", storage, bucket_size);
    printf("Dropping the packet requests ....");
    
}
