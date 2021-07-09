# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main ()
{
char buffer[5]="hello";
int fd1, ret;
fd1 = creat ("txt1.txt", 0777);
ret = write (fd1, buffer,  sizeof(buffer));
  
}
