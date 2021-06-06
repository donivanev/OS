// • Да се напише програма на C, която получава като параметри в командния ред 2 команди (без параметри). 
//   Програмата реализира конструкцията: команда1 || команда2

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int status;
	int pid = fork();

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		pid_t childPid = wait(&status);

		if (status != 0)
		{
			if (execlp(argv[2], argv[2], 0) != -1)
			{
				execlp(argv[2], argv[2], 0);
			}
			else
			{
				write(1, "Command 2 not found.\n", 22);
				exit(-1);
			}
		}
	}
	else
	{
		if (execlp(argv[1], argv[1], 0) != -1)
		{
			execlp(argv[1], argv[1], 0);
		}
		else
		{
			write(1, "Command 1 not found.\n", 22);
			exit(-1);
		}
	}

	exit(0);
}
