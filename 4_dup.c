# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main ()
{
int fd1, fd2;
fd1 = open ("txt1.txt",O_RDONLY|O_CREAT, 777);
close (2); 
// we are closing error fd. 
// so generated fd should be kept in slot 2
dup(fd1);
        while(1)
	{
	}
}
