// • Да се напише програма на C, която отпечатва PID-a на процесите родител и дете. 
//   След това в детето : 1. със sleep да се задържи достатъчно дълго, за да приключи своята работа процеса родител.
//                        2. с достатъчно дълъг цикъл без печат да се задържи детето, за да приключи своята работа процеса родител.

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid = fork();

	if (pid == -1)
	{
		write(1, "Error.\n", 8);
		exit(-1);
	}
	else if (pid > 0)
	{
		printf("%d %d\n", getpid(), getppid());
		write(1, "I am parent", 11);
	}
	else
	{
		//sleep(5);
		for (int i = 0; i < 1000000000; ++i)
		{
			
		}
		printf("%d %d\n", getpid(), getppid());
		write(1, "I am child", 10);
	}

	exit(0);
}
