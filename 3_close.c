# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>

int main ()
{
int fd1,ret;
fd1 =  open ("INDIA.txt",O_RDONLY|O_CREAT, 0777);
ret = close (fd1);
printf ("\n 0 is Success \n -1 is failure");
printf ("\n Machi Enda result %d", ret); 
 while(1)
	{
	}

}
