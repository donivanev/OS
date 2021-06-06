// •	Да се напише програма на C, която записва във файл 25 байта, 
//    чете от него по 10 байта и отпечатва какво връща read.

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_RDWR | O_CREAT | O_EXCL, 0644);
	char* buff[10];
	int r;

	if(fl == -1)
	{
		write(1, "Error while opening a file.\n", 29);
	}

	write(fl, "Sentence with 25 chars.\n", 25);

	while(r = read(fl, buff, 10) > 0)
	{
		write(1, buff, r);
	}

	close(fl);
	exit(0);
}
