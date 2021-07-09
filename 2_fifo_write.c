// NAMED PIPE - OR FIFO //
/*
BY SHRIRAM K VASUDEVAN
The normal pipe program that we saw was unable to communicate to a different proces
They can be used for communication between related processes alone.
Now here we have 2 different programs for FIFO example.
we are going to communicate between these different processes.
Write cant complete its execution, unless reader reads the data written.
*/
// THIS IS FIFO WRITE PROGRAM
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
int main ()
{
int fd, retval;
char buffer [8] = "TESTDATA";
fflush (stdin);
retval = mkfifo ("/tmp/myfifo", 0666);
// We have to create the fifo. we are permitted to create in
// /tmp directory alone. And we have given permissions 0666.
fd = open ("/tmp/myfifo",O_WRONLY);
// As the fifo is already created, we can just open it now.
// and the location of the file is "/tmp/myfifo"
// we can try the same step out there from Command Prompt as well.
write (fd,buffer,sizeof(buffer));
// we are now writing into the fifo.
// That is the fd is the point of identification.
close (fd);
return 0;
}
