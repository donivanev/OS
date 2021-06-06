// • Да се напише програма на C, която получава като параметри име на файл и команда с опции и аргументи. 
//   Да се изпълни команда, която отпечатва редовете от файл, съдържащи символния низ int. 
//   Да се изпълни подадената команда с опции и аргументи като се отпечата кода й на завършване.

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int pid = fork();
	int status, exitCode;

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		wait(&status);

		write(1, "\n", 2);
		printf("%s %d\n", "Exit code is: ", exitCode);
		write(1, "\n", 2);
		execvp(argv[2], argv + 2);
	}
	else
	{
		exitCode = execlp("grep", "grep", "int", argv[1], 0);
	}

	exit(0);
}
