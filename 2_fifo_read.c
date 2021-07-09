// NAMED PIPE - OR FIFO //
/*
BY SHRIRAM K VASUDEVAN
The normal pipe program that we saw was unable to communicate to a different proces
They can be used for communication between related processes alone.
Now here we have 2 different programs for FIFO example.
we are going to communicate between these different processes.
// Read would wait until Written!
*/
// THIS IS FIFO READ PROGRAM
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
int main()
{
int fd, retval;
char buffer[8];
fd = open ("/tmp/myfifo",O_RDONLY);
// As we have already created the fifo in write program, we have to just open it.
retval = read (fd, buffer, sizeof (buffer));
// we are reading and putting the content into the buffer.
fflush(stdin);
// we are just flushing the data, which might be present already
write(1, buffer, sizeof (buffer));
// we are now reading the content out from the buffer and putting it on the screen
close (fd);
return 0;
}
