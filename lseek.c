# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int main ()
{
char buffer[10]="hellosirho";
int fd1, ret, ret1;
fd1 = creat ("txt1.txt", 0777);
ret = write (fd1, buffer, sizeof(buffer));
ret1= lseek (fd1, 12, SEEK_CUR);
ret = write (fd1, buffer, sizeof(buffer));
printf ("%d",ret1);
}

//SEEK_END, SEEK_SET, SEEK_CUR
