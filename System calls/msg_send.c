/*
The message queue is one of the interprocess communication mechanisms that has a Sender and Receiver. Receiver will wait until the sender sends the message.

API's for performing the queue operation.

ftok()
1. msgget() - Will initialize the queue
2. msgsnd() - to send messages
3. msgrcv() - to receive the messages
4. msgctl() - Control action that is inclusive of deleting the queue.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>



/* Create a structure for sending the message */
struct msgbuf
{
long mtyp;
int x;
};

// sending process places msg into queue via a msg passing module which is as follows

int main(void)
{
struct msgbuf msg;

int msgid;

key_t key;

// step 1 - creating key

// each process must share a common key inorder to gain access to the queue in the first place. This key should be the same in sending and receiving process

// key_t  ftok(const  char  *pathname, int proj_id);

key = ftok("msg_send.c",'c');

// ftok  - convert a pathname and a project identifier to a System V IPC key

if( key == -1)
{
perror("An error in key gen\n");
exit(1);
}

// step 2 - creating msgid

// each msg is given an id for processes to select msgs appropriately

// int msgget(key_t key, int msgflg);

msgid = msgget(key,0644|IPC_CREAT);

if(msgid == -1)
{
perror("An error in msgid gen\n");
exit(1);
}

// else if, success,  msgid will be positive integer

printf ("The msgid generated is %d\n",msgid);

printf("Enter the data to send : \n");

scanf("%d",&msg.x);

msg.mtyp = 2; // receiver should also set the mtype as 2 .. check man msgsnd

//step 3 - send the msg

// int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);

int r = msgsnd(msgid,&msg,sizeof(msg),0);
if(r == -1)
{
perror("An error in msgsnd:\n");
exit(1);
}

// else success

// to delete the id, when the work is over, not mandatory

//int msgctl(int msqid, int cmd, struct msqid_ds *buf);

/*if(msgctl(msgid,IPC_RMID,NULL)==-1)

{
perror("msgctl");
exit(1);
}
*/
// check the output by commenting the block for msgctl()
// it can be seen that the output is received in the receiver even if the sender program exists before running the receiver pgm.

return 0;
}

// To delete the msgid give
// ipcrm -q msgid through command line!

