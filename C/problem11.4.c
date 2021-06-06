// • Да се напише програма на C, която чете последователност от символи от файл, чието име е подадено като първи параметър. 
//   Извежда ги на стандартния изход. Първите 3 символа от всеки ред добавя след края на файл, чието име е подадено като втори параметър.

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_RDONLY);
	int fl2 = open(argv[2], O_WRONLY | O_APPEND);
	char buff[128];
	int r;

	if (fl == -1)
	{
		write(1, "Error while reading file 1.\n", 29);
		exit(-1);
	}

	if (fl2 == -1)
	{
		write(1, "Error while reading file 2.\n", 29);
		exit(-1);
	}

	int counter = 0;

	while (r = read(fl, buff, 1) > 0)
	{
		write(1, buff, r);

		if (counter < 3)
		{
			write(fl2, buff, r);
			counter++;
		}

		if (buff[0] == '\n')
		{
			counter = 0;
		}
	}

	close(fl);
	close(fl2);
	exit(0);
}
