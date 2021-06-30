#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd;
	char *line;
	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		printf("main: %s\n", line);
}