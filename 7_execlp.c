# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
int main ()
{

	printf ("\n I am in process 1"); 
	execlp ("ls", "ls", "-lrt");
	printf ("\n I will not be respected"); 
	return 0; 
}

