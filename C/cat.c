// • Да се напише програма на C, която реализира командата cat (без параметри)

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char buff[512];

	for(;;)
	{
		scanf("%s", buff);
	}

	exit(0);
}
