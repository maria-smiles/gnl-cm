#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int byte_all;

int main(int argc, char **argv)
{
	char *line;
	int fd;
	byte_all = 0;
	printf("argc = %d\n", argc);
	printf("int max = %d\n", INT_MAX);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Cannot open file.\n");
			return (-1);
		}
	}
	else if (argc == 1)
		fd = 0;
	else
	{
		printf("too many arguments");
		return (-1);
	}

	printf("Buf size = %d\n", BUFFER_SIZE);
	int r;

	while ((r = get_next_line(fd, &line, &byte_all)))
	{
		printf("r = %d\n", r);
		printf("New line = %s\n", line);
		
		/*
		printf("New line = ");
		size_t i = 0;
		size_t len = ft_strlen(line);
		while (i < len)
		{
			printf("%d ", line[i]);
			i++;
		}
		printf("\n");
		*/
	}
	printf("after while r = %d\n", r);
	printf("New line = %s\n", line);

	/*
	printf("New line = ");
	size_t i = 0;
		size_t len = ft_strlen(line);
		while (i < len)
		{
			printf("%d ", line[i]);
			i++;
		}
printf("\n");
	*/

	printf("all bytes = %d\n", byte_all);

}


//int main(int argc, char **argv)
//{
//	(void)argv;
//	int fd;
//	char *line;
//	int i;
//
//	line = NULL;
//	printf ("argc = %d\n", argc);
//	if (argc == 2)
//	{
//		fd = open(argv[1], O_RDONLY);
//		if (fd == -1)
//		{
//			printf("Cannot open file.\n");
//			return (-1);
//		}
//
//		while ((i = get_next_line(fd, &line)) != -1)
//		{
//			printf("i = %d %s\n", i, line);
//			free(line);
//		}
//
//		printf("i = %d %s\n", i, line);
//		free(line);
//	}
//	else if (argc == 1)
//	{
//		while ((i = get_next_line(0, &line)) == 1)
//		{
//			printf("i = %d %s\n", i, line);
//			free(line);
//		}
//
//		printf("i = %d %s\n", i, line);
//		free(line);
//	}
//	else
//	{
//		printf("too many arguments");
//		return (-1);
//	}
//
//
//	return (0);
//}
