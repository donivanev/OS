// • Да се напише програма на C, която получава като параметър в командния ред  една команда (изпълним файл) и списък с параметри за нея. 
//   Поражда процес дете и сменя образа му с командата. 
//   В родителя изчаква наследника да приключи и извежда номера му и кода на завършване.

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
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		pid_t childPid = wait(&status);
		printf("My child with pid %d has finished with status %d\n", 
				childPid, status);
	}
	else
	{

		execvp(argv[0], argv++);
	}

	exit(0);
}
