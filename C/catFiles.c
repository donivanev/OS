// • Да се напише програма на C, която реализира командата cat [f1...]

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl;
	char buff[128];
	int r;

	for (int i = 2; i < argc; ++i)
	{
		fl = open(argv[i], O_RDONLY);

		if (fl == -1)
		{
			write(1, "Error opening file\n", 20);
		}

		while(r = read(fl, buff, 128))
		{
			write(1, buff);
		}

		close(fl);
	}

	exit(0);
}
