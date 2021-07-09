/*
////////////////////////////SYSTEM v IPC - PIPE /////////////////////////////
By SHRIRAM K VASUDEVAN
pipe is a unidirectional mechanism of IPC.
You can send and receive data from source to destination, but not at a time.
PIPE can be created with pipe () system call and it will return two file descripto
the argument to be passed to pipe () should be an array of integers.
int pipefd[2]; can be a valide sample here.
after the system call is executed, it would return 2 fds one fd[0] and other fd[1
fd[0] - Always should be kept as read end. fd[1] - always should be write end.
changing the above may result in unpredicatable results.
More importantly, pipes have to be used with related processes.
they are un named. And the data that u pass, will come out in the same order.
///////////////////////////////////////////////////////////////////////////////
*/
# include <stdio.h>
# include <unistd.h>
int main(void)
{
int pipefd[2];
// this is to be passed to the pipe system call.
int ret;
char buffer[15];
// this buffer is where I will keep the data in.
pipe (pipefd);
//I have now piped it. Means we have formed the pipe.
//There will be 2 return values. One for read and another one for write.
ret = fork ();
// Am creating a child process.
// This will now throw two return values. one > o and other == 0.
// >0 is the for parent, equal to 0 is child.
////////////////////////////////// FIRST PART OF THE PROGRAM //////////////////////
if (ret > 0)
{
fflush (stdin);
// am cleaning the standard input line.
// that could have had some data, so I flushed it.
printf (" \n Am Parent ");
// Am just confirming that am in parent and data write will happen after this.
write (pipefd[1],"HELLOMR.SHRIRAM",15);
// we are now writing the content into Write end of the pipe.
// i.e. the data is now poured.
}
////////////////////////////////// SECOND PART OF THE PROGRAM /////////////////////
if (ret == 0)
{
sleep (5);
fflush (stdin);
// am cleaning the standard input line.
// that could have had some data, so I flushed it.
printf (" \n AM CHILD MAN ");
// Data already written the write end can be read from here.
read (pipefd[0],buffer,sizeof(buffer));
// The data is now read, but we need to display in the screen right?
// for that purpose we are keeping the data in buffer.
// from buffer we can write it to display
write (1,buffer,sizeof(buffer));
}
return 0;
}
