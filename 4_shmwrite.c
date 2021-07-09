// SHARED MEMORY - WRITE
/* THIS IS THE PROGRAM FOR SHARED MEMORY - WRITE
BY SHRIRAM K VASUDEVAN!
Well, This is yet another mechanism of Interprocess Communication.
This can be done between any two processes, That is they need not be related.
By default a page of memory (4kbytes) would be allocated for Shared memory
from any process.
Assume process 1 wants to access its Shared Memory area, It has to get attached
to it first. Though its P1's memory area, it cannot get access as such.
Only after attaching it can gain access.
There are three steps:
1. Initialization
2. Attach
3. Detach.
*/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
int main ()
{
int retval,shmid;
void *memory = NULL;
char *p;
/////////////// STAGE 1 OF THE PROGRAM /////////////////////
// INITIALIZATION OF THE SHARED MEMORY.
shmid = shmget ((key_t)123456789, 6, IPC_CREAT|0666 );
// We are getting the Shm initialized.
if (shmid < 0)
{
printf ("\n The Creation has gone as a failure, Sorry");
shmid = shmget ((key_t)123456789, 6, 0666);
// As it is already created, we are just getting permissions for the same.
}
printf ("\n We are getting the shared memory created %d", shmid);
//////////// STAGE 2 OF THE PROGRAM ///////////////////////
// ATTACHMENT TO THE SHARED MEMORY.
memory =shmat (shmid, NULL, 0);
//On success shmat() returns the address of the attached shared memory segment of
// so y we are declaring void *memory = NULL; in the start of the code.
// We are attaching the process to the shared memory.
if (p == NULL)
{
printf ("\n Attachment failure, Sorry");
return 0;
}
p=(char *) memory;
// we are entering the address space.
// So we need to specify the data type.
// here we are sending the characters, so we need to cast it to char
memset (p, '\0', 6);
// we are cleaning before using.
memcpy (p,"hello", 6);
// we are now writing the content.
////////////// STAGE 3 OF THE PROGRAM /////////////////////
// DETACHING AS WE HAVE ALREADY WRITTEN.
retval = shmdt (p);
if (retval < 0)
{
printf ("\n Suffered Detachment");
return 0;
}
}