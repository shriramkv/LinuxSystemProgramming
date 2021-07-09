# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main ()
{
int fd1, fd2, fd3;
fd1 = open("txt1.txt",O_RDONLY|O_CREAT, 0777);
fd2 = open("txt2.txt",O_RDONLY|O_CREAT, 0777);
fd3 = dup2(fd1, fd2);
// here we are duplicating according to our wish. i.e. fd1 to fd2.
        while(1)
	{
	}
}

