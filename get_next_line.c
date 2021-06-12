//
// Created by Leann Alaskan on 5/25/21.
//
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 50
#endif //BUFFER_SIZE

void	ft_strclr(char *ost)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(ost);
	while (i < len)
	{
		ost[i] = '\0';
		i++;
	}
}

char	*ft_clrnew(size_t count)
{
	char	*line;

	line = malloc(sizeof(char) * (count + 1));
	if (!line)
		return (NULL);
	ft_strclr(line);
	return (line);
}

char	*check_ost(char *ost, char **line)
{
	char	*p_n;
	size_t	tmp;

	p_n = NULL;
	if (ost)
	{
		p_n = ft_strchr(ost, '\n');
		if (p_n)
		{
			tmp = ft_strlen(ost);
			*p_n = '\0';
			*line = ft_strdup(ost, 0);
			ft_strcpy(ost, ++p_n, tmp);
		}
		else
		{
			*line = ft_strdup(ost, 0);
			ft_strclr(ost);
		}
	}
	else
		*line = ft_clrnew(1);
	return (p_n);
}

size_t	ft_read(char *ost, char **line, int fd, char *buf)
{
	char		*p_n;
	size_t		byte;
	char		*tmp;

	p_n = check_ost(ost, line);
	while (!p_n)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		buf[byte] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			p_n++;
			ost = ft_strdup(p_n, 0);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf, 1);
		free(tmp);
	}
	return (byte);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	size_t		byte;	
	static char	*ost;

	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf || (fd < 0 || fd > 19))
		return (-1);
	byte = ft_read(ost, line, fd, buf);
	if (byte == 0 || !byte)
		free (buf);
	if (byte == -1)
		return (-1);
	else if (byte != 0 || (ost && ft_strlen(ost) != 0) || \
				(ft_strlen(*line) != 0 && byte != 0))
		return (1);
	else
		return (0);
}
