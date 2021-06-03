//
// Created by HardWorker on 01.06.2021.
//
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *check_reminder(char *reminder, char **line);

int get_next_line(int fd, char **line)///1, 0, -1
{
	char buf[BUFFER_SIZE + 1];
	int byte_was_read;
	char *p_n;
	static char *reminder;
	char *tmp;

	p_n = check_reminder(reminder, line);
	while(!p_n && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (byte_was_read != 0 || ft_strlen(reminder) != 0 || ft_strlen(*line) != 0)
		return (1);
	else
		return (0);
	/*return (byte_was_read || ft_strlen(reminder) || ft_strlen(*line)) ? 1 :
	0;//byte_was_read != 0 - что-то было прочитано, или в остатке что-то есть: reminder lenth != 0. line lenth != 0 -
*/
}

char *check_reminder(char *reminder, char **line)
{
	char *p_n;

	p_n = NULL;
	if (reminder)
	{
		if ((p_n = ft_strchr(reminder, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(reminder);
			ft_strcpy(reminder, ++p_n);
		}
		else
		{
			*line = ft_strdup(reminder);
			ft_strclr(reminder); //что она чистит?!
		}
	}
	else
	{
		*line = ft_strnew(1);//ft_strnew аллоцирует переданное кол-во памяти и заполняет нулями
	}
	return (p_n);
}