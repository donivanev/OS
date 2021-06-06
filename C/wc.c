// • Да се напише програма на C, която реализира командата wc f1

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int l = 0, w = 0, c = 0, r = 0;
    char buff[1];
    int fl = open(argv[2], O_RDONLY);

    if (fl == -1)
    {
    	write(1, "Error while opening the file.\n", 31);
    	exit(1);
    }

    while(r = read(fl, buff, 1) > 0)
    {
    	if (buff[0] != ' ' && buff[0] != '\t')
    	{
    		c++;
    	}
    	if (buff[0] == ' ' || buff[0] == '\t' || buff[0] == '\n')
    	{
    		w++;
    	}
    	if (buff[0] == '\n')
    	{
    		l++;	
    	}
    }

    printf("%d %d %d %s\n", l, w, c, argv[2]);

    close(fl);
    exit(0);
}
