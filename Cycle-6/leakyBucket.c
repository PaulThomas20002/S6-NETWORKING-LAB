#include <stdio.h>
#include <stdlib.h>

void main(){
    int storage = 0, input_pkt = 4, output_pkt = 1, bucket_size = 10;
    int packetnum = 4;
    
    printf("Enter the Input rate : ");
    scanf("%d", &input_pkt);
    
    printf("Enter the Output rate : ");
    scanf("%d", &output_pkt);
    
    printf("Enter the Bucket size : ");
    scanf("%d", &bucket_size);
    
    for ( int i = 0; i < packetnum; i++){
        int size_left = bucket_size - storage;
        
        if ( input_pkt <= size_left ){
            storage = storage + input_pkt;
        }
        else {
            printf("\nPacket Loss : %d", input_pkt);
        }
        
        printf("\nstorage : %d  of bucket_size : %d", storage, bucket_size);
        storage = storage - output_pkt;
    }
    
    printf("\nStorage : %d  of bucket_size : %d", storage, bucket_size);
    printf("Dropping the packet requests ....");
    
}
