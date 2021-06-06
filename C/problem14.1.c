// • Да се напише програма на C, която създава файл abc в текущата директория и го отваря за писане. 
//   Създава 2 процеса, които пишат в него hello.

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_WRONLY | O_CREAT | O_EXCL, 0644);

	if (fl == -1)
	{
		write(1, "Error opening a file.\n", 23);
		exit(-1);
	}

	int pid = fork();

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		write(fl, "hello\n", 7);
	}
	else
	{
		write(fl, "hello\n", 7);
	}

	close(fl);
	exit(0);
}
