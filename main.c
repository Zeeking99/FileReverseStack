#include <stdio.h>
#include <string.h>
#include "charstack.h"

int main(int argc, char ** argv)
{
	int f =	reversefile(argv[1], argv[2]);

	if(f)
		printf("File copied successfully\n");
	else
		printf("Error -- File not copied\n");
	return 0;
}
