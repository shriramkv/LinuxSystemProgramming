// FORK IS USED TO CREAT CHILD.
/*
Fork internally calls clone function.
fork system call when called, it will return 2 return values.
one is > 0 that is for parent.
one is ==0 that is for child.
With this identity we can spot which is child and which is parent.
It is not mandatory that parent should be executed first always.
Child can also get execution time.
*/
# include <stdio.h>
# include <unistd.h>
int main(void)
{
int ret;
ret = fork ();
// Am creating a child process.
// This will now throw two return values. one > o and other == 0.
// >0 is the for parent, equal to 0 is child.
////////////////////////////////// FIRST PART OF THE PROGRAM //////////////////////
if (ret > 0)
{
printf (" \n Am Parent ");
printf (" \n My PID is %d",getpid());
}
////////////////////////////////// SECOND PART OF THE PROGRAM /////////////////////
if (ret == 0)
{
// sleep (5); // Check this significance
printf (" \n AM CHILD MAN ");
printf (" \n My PID is %d",getpid());
printf (" \n My Parent PID is %d",getppid());
}
return 0;
}
/*
shri@ubuntu:~$ ./fork
AM CHILD MAN
My PID is 6713
My Parent PID is 6712
Am Parent
My PID is 6712shri@ubuntu:~$
*/
