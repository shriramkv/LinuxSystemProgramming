# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> 
int main ()
{

	int return_value; 
	return_value = system ("ls -lrt/");
	printf ("\n Return Valur %d", return_value);
	return 0; 
}

