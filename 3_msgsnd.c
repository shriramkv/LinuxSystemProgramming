///////////// CODE FOR QUEUE - MESSAGE SENDER /////////////////
/*
// BY SHRIRAM K VASUDEVAN
SYSTEM V IPC MECHANISMS - QUEUE
The message queue is one of the interprocess communication mechanisms that can sy
Sender and Receiver. Receiver will wait until the sender sends the message.
Also we have another advantage. i.e. after usage the memory space will be freed by
Assume that we have 2 process, Process 1 and Process 2.
we need to have an identifier for the communication between the two process.
We are keeping it as 1 here. For that only we are having long mtype as a compone
So we need to make long mtype = 1; here in our case.
We just need 3 api's for performing the queue operation.
1. msgsnd - Will initialize the queue
2. msgrcv - Will be used to receive the messages
3. msgctl - Control action that is inclusive of deleting the queue.
Please keep in mind that you may require administrator privilleges to run, create
*/
// Header files on IPC and msg have to be included with normal other headers
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
// We need to create a structure for sending the message and to decide on type of t
struct msgbuf
{
long mtype; // For message type.. i.e. From which process to which process.
char msgtxt[200]; // The text data that we are going to send.
};
int main(void)
{
struct msgbuf msg;
// Making an instance of the structure.
int msgid;
// every message is represented by an id by which we can access the message in the
key_t key;
// Every queue needs a key, which the sender and receiver will agree upon when they
// it is of type key_t as defined in man page of msgsnd.
///////////////////// STAGE 1 of PROGRAM ////////////////////////////////////////
if((key=ftok("3_msgsnd.c",'b'))== -1)
//ftok function generate the key it will return the key if successful else return -
//ftok is file to key
// we are generating a key with the file that we create itself.
{
perror("key"); // if not created perror function will let us know why it has not been cr
exit(1);
}
///////////////////// STAGE 2 of PROGRAM ////////////////////////////////////////
if((msgid=msgget(key,0644|IPC_CREAT))==-1)
// we are generating a message id, thro this system call
// if successful it will return the message id through which we can access the queu
{
perror("msgid");
// if not formed it will give the error message.
exit(1);
}
printf ("\n the msgid is %d",msgid);
// We are just printing the message id to get a confirmation.
printf("enter the text");
// it will ask you to type the data when you execute.
msg.mtype=1;
// we are setting the message type here. i.e. an agreement between the processes.
while(gets(msg.msgtxt),!feof(stdin))
//reading and appending the message typed on the
//stdin to the queue by the msgsnd fuction call
{
//////////// Third Stage of the program /////////////////////////////////////
if(msgsnd(msgid,&msg,sizeof(msg),0)==-1)
// Here for sending the message we are passing the msgid, address of msg and size o
// as we are not going to use any of the flags, we are marking 0 as 4th argument.
// it will return -1 if an error has been created.
{
perror("msgsnd");
exit(1);
}
}
//////////// Stage 4 of the program //////////////////////////////////////////
if(msgctl(msgid,IPC_RMID,NULL)==-1)
// to delete the id, when my work is over..
{
perror("msgctl");
exit(1);
}
return 0;
}
// To delete the msgid thro command line!
// ipcrm -q msgid
