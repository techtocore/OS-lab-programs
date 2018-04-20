/*
THIS IS THE RECEIVER PROGRAM FOR THE MESSAGE QUEUE
Most part of the program would be the same.
Except that, we have used msgsnd there, here will use, msgrcv.

Same are the header files.*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

/* We need to create a structure for receiving the message and to decide on type of t*/

struct msgbuf
{
long mtype;
int x;
};


int main(void)
{
struct msgbuf msgr;

int msgid;

key_t key;

//step 1 - creating key

// each process must share a common key inorder to gain access to the queue in the first place. This key should be the same in sending and receiving process

if((key=ftok("msg_send.c",'c'))== -1)

{
perror("key");
exit(1);
}
//step 2 - creating the msg id

msgid = msgget(key,0644);

if(msgid == -1)
{
perror("msgid");
exit(1);
}

//step 3 - receiving the msg

//ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);


size_t r = msgrcv(msgid,&msgr,sizeof(msgr),2,0);

if(r == -1)
{
perror("msgrcv");
exit(1);
}

printf("Message received from sender : %d\n",msgr.x);

return 0;
}


