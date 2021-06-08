//
// Created by Leann Alaskan on 5/25/21.
//
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char *check_ost(char *ost, char **line)
{
	char *p_n;
	size_t tmp;

	p_n = NULL;
	if (ost)
	{
		if ((p_n = ft_strchr(ost, '\n')))
		{
			tmp = ft_strlen(ost);
			*p_n = '\0';
			*line = ft_strdup(ost);
			ft_strcpy(ost, ++p_n, tmp);
		}
		else
		{
			*line = ft_strdup(ost);
			ft_strclr(ost);
		}
	}
	else
	{
		*line = ft_clrnew(1);
	}
	return (p_n);
}

int get_next_line(int fd, char **line, int *byte_all)
{
	char buf[BUFFER_SIZE + 1];
	int byte;
	char *p_n;
	static char *ost;
	char *tmp;
	
	if (fd < 0 || fd > 19)
	return (-1);
	p_n = check_ost(ost, line);
	while(!p_n && (byte = read(fd, buf, BUFFER_SIZE)))
	{
		*byte_all += byte;
		buf[byte] = '\0';
		if((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			p_n++;
			ost = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (byte == -1)
		return (-1);
	else if (byte != 0 || (ost && ft_strlen(ost) != 0) || (ft_strlen(*line) != 0 && byte != 0))
		return (1);
	else
		return (0);
}
