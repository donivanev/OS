// • Да се напише програма на C, която реализира командата tee f1

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
	int r;
	char buff[128];

	while(r = read(0, buff, 128))
	{
		write(fl, buff, r);
	}

	close(fl);
	exit(0);
}
