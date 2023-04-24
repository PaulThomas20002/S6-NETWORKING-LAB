//Sliding Window Protocol
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
int n,r;


struct frame
{
char ack;
int data;
}frm[10];
int sender(void);
void recvack(void);
void resend(void);
void resend1(void);
void goback(void);
void selective(void);
void StopnWait(void);

void main()
{
int c;
x:printf("\n1.Selective Repeat\n2.Goback\n3.Stop and Wait\n4.Exit\n");
printf("\nEnter your choice:");
scanf("%d",&c);
switch(c)
{
case 1:selective();
break;
case 2:goback();
break;
case 3:StopnWait();
break;
case 4:exit(0);
break;

}
goto x;
}


void goback()
{
sender();
recvack();
resend1();
printf("\nAll packets sent successfully\n");
}


void selective()
{
sender();
recvack();
resend();
printf("\nAll packets sent successfully");
}




int sender()
{
int i;
printf("\nEnter the no. of packets to be sent:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\nEnter data for packets[%d]",i);
scanf("%d",&frm[i].data);
frm[i].ack='y';
}
return 0;
}


void recvack()
{
int i;
rand();
r=rand()%n;
frm[r].ack='n';
for(i=1;i<=n;i++)
{
if(frm[i].ack=='n')
printf("\nThe packet number %d is not received\n",r);
}
}
void recvack1()
{
int i;
sleep(2);
}

void resend()
{
printf("\nResending packet %d",r);
sleep(2);
frm[r].ack='y';
printf("\nThe received packet is %d",frm[r].data);
}


void resend1()
{
int i;
printf("\nResending from packet %d",r);
for(i=r;i<=n;i++)
{
sleep(2);
frm[i].ack='y';
printf("\nReceived data of packet %d is %d",i,frm[i].data);
}
}

void StopnWait()
{
sender();
recvack1();  
printf("\nAll packets sent successfully");
}
