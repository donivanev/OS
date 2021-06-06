// • Да се напише програма на C, която реализира командата cat >> f1

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_APPEND | O_CREAT | O_EXCL, 0744);
	char buff[128];
	int r;

	if (fl == -1)
	{
		write(1, "Error opening a file.", 21);
		exit(1);
	}

	while(r = read(fl, buff, 128))
	{
		write(fl, buff, 128);
	}

	close(fl);
	exit(0);
}
