// •Да се напише програма на C, която реализира командата cp f1 f2

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_RDONLY);
	int fl2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
	char* buff[128];
	int r;

	if (fl == -1)
	{
		write(1, "Error while opening file 1.\n", 31);
		exit(1);
	}

	if (fl2 == -1)
	{
		write(1, "Error while creating file 2.\n", 30);
		exit(-1);
	}

	while(r = read(fl, buff, 1) > 0)
	{
		if(write(fl2, buff, r) != r)
		{
			write(1, "\ncopy: write error\n", 21);
			exit(-1);
		}
		else
		{
			write(fl2, buff, r);
		}
	}

	close(fl);
	close(fl2);
	exit(0);
}
