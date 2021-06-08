//
// Created by Leann Alaskan on 5/25/21.
//

#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H


#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

static size_t BUFFER_SIZE;
//#elif (BUFFER_SIZE > INT_MAX)
	//#define BUFFER_SIZE 2147483646
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 10
#endif



int get_next_line(int fd, char **line, int *byte_all);
//int get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
void	*ft_memset (void *destination, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);
void ft_strclr(char *reminder);
char *ft_clrnew(size_t count);

#endif //GNL_GET_NEXT_LINE_H
