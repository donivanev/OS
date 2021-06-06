// • Да се напише програма на C, която реализира командата cut -cm-n f1 (m и n да се четат от входа)

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_RDONLY);
	char buff[128];
	int r, n = 0, m = 0;

	if(fl == -1)
	{
		write(1, "Error opening a file.\n", 23);
		exit(-1);
	}

	printf("Enter m: ");
	scanf("%d", &m);
	printf("Enter n: ");
	scanf("%d", &n);

	int counter = 0;
	lseek(fl, m, SEEK_SET);

	while (r = read(fl, buff, 1) > 0)
	{
		if (counter < n - m)
		{
			write(1, buff, r);
			counter++;
		}
		else
		{
			exit(0);
		}
	}

	close(fl);
	exit(0);
}
