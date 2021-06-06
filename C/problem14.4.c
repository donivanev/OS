// • Да се напише програма на C, която получава като параметри от команден ред две команди (без параметри) и име на файл в текущата директория. 
//   Ако файлът не съществува, го създава. Програмата изпълнява командите последователно, по реда на подаването им. 
//   Ако първата команда завърши успешно, програмата добавя нейното име към съдържанието на файла, подаден като команден параметър. 
//   Ако командата завърши неуспешно, програмата уведомява потребителя чрез подходящо съобщение.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[3], O_WRONLY | O_APPEND | O_CREAT, 0644);
	char buff[128];

	if (fl == -1)
	{
		write(1, "Error while opening the file.\n", 31);
		exit(-1);
	}

	int pid = fork();
	int status;

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		wait(&status);

		int i;
		for (i = 0; argv[1][i] != '\0'; ++i);
		write(fl, argv[1], i);

		close(fl);
		execlp(argv[2], argv[2], 0);
	}
	else
	{
		if (execlp(argv[1], argv[1], 0) == -1)
		{
			write(1, "Error while executing command 1.\n", 33);
			exit(-1);
		}
	}

	exit(0);
}
