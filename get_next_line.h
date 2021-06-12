#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1, int endnul);
char	*ft_strjoin(char const *s1, char const *s2, int endnul);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	ft_strcpy(char *dst, const char *src, size_t dstsize);

#endif //GET_NEXT_LINE_H
