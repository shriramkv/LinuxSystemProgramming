# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main ()
{
int fd1, fd2;
fd1 = open ("txt1.txt",O_RDONLY|O_CREAT, 0777);
fd2 = fcntl (fd1, F_DUPFD, 0); 
/* fd2 = dup(fd1); */
       while(1)
	{
	}
}
