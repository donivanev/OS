// • Да се напише програма на C, която получава като параметър в командния ред една команда и при успешното й изпълнение извежда на стандартния изход името на командата. 

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int status = 0;
	int pid = fork();

	if (pid == -1)
	{
		write(1, "Couldn't fork!\n", 16);
		exit(-1);	
	}
	else if (pid > 0)
	{
		wait(&status);

		int i;
		while(argv[1][i] != '\0')
		{
			i++;
		}

		write(1, argv[1], i);
	}
	else
	{
		execlp(argv[1], argv[1], 0);
	}

	exit(0);
}
