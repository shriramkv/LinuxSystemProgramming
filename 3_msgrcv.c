/*
//// BY SHRIRAM K VASUDEVAN
THIS IS THE RECEIVER PROGRAM FOR THE MESSAGE QUEUE .. MSGRCV.C
Most part of the program would be the same.
Except that, we have used msgsnd there, here will use, msgrcv.
that we are receiving the message from the sender. that's all! we are done.
*/
// Same are the header files.
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
////////////////////// Stage 2 of program ///////////////////////////////////////
// As we have already created the msgid, we need not create it again.
// so we just need to get permissons for access.
if((msgid=msgget(key,0644))==-1)
// if failure, we will get -1 as return value.
{
perror("msgid");
exit(1);
}
/////////////////////Stage 3 of the program //////////////////////////////////////
for(;;)
// infinite loop, i.e. the user can keep on typing till 200. that is the limit that
{
if(msgrcv(msgid,&msg,sizeof(msg),1,0)==-1)
// here we are using address of instance msg and 1 the number that says what type t
{
perror("msgrcv");
exit(1);
}
printf("%s\n",msg.msgtxt);
// this is where u will get it printed!
}
return 0;
}
