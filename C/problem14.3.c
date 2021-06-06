// • Да се напише програма на C, която изпълнява последователно подадените ѝ като параметри команди, като реализира следната функционалност постъпково:
//     -	main cmd1 ... cmdN изпълнява всяка от командите в отделен дъщерен процес.
//     -	... при което се запазва броя на изпълнените команди, които са дали грешка и броя на завършилите успешно.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int pid, status, counter = 0;

	for (int i = 1; i < argc; ++i)
	{	
		pid = fork();

		if (pid == -1)
		{
			write(1, "Error while forking.\n", 22);
			exit(-1);
		}
		else if (pid > 0)
		{
			wait(&status);
		}
		else
		{
			if (execlp(argv[i], argv[i], 0) == -1)
			{
				counter++;
			}
		}
	}

	printf("%s %d\n", "Error commands: ", counter);

	exit(0);
}
