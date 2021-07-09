// Code Starts here. 
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main ()
{
	int fd1, ret;
        fd1 = open ("test.txt", O_RDONLY|O_CREAT, 0777);
        ret = fcntl (fd1, F_GETFL);
        if (ret == O_RDONLY)
	{
		printf ("  READONLY \n" );
        }
        else if (ret == O_WRONLY)
	{
		printf ("  WRITEONLY \n" );
        }
 else 
  	printf ("  READONLY \n" );
}

