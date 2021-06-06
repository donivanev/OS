// • Да се напише програма на C, която получава като параметри в командния ред 2 команди (без параметри). 
//   Програмата реализира конструкцията: команда1 && команда2

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int status, status2;
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
			write(1, "Couldn't find command.\n", 24);
			exit(0);
		}
	        if (execlp(argv[2], argv[2], 0) != -1)
		{
			execlp(argv[2], argv[2], 0);
		}
		else
		{
			write(1, "Couldn't find command.\n", 24);
			exit(-1);
		}
	}
	else
	{
		if(execlp(argv[1], argv[1], 0) != -1)
		{
			execlp(argv[1], argv[1], 0);
		}
		else
		{
			exit(-1);
		}
	}

	exit(0);
}
