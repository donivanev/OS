// • Да се напише програма на C, която чете последователност от символи от стандартния вход. 
//   Записва ги във файл, чието име е подадено като първи параметър. 
//   Замества символите за табулация с '>>>' и резултата извежда на стандартния изход за грешки. 

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);
	char buff[128];
	int r;

	if (fl == -1)
	{
		write(1, "Error while opening a file.\n", 29);
		exit(-1);
	}

	while (r = read(0, buff, 1))
	{
		if (buff[0] == '\t')
		{
			write(fl, ">>>", 3);
		}
		else
		{
			write(fl, buff, r);
		}
	}

	write(2, buff, r);

	close(fl);
	exit(0);
}
