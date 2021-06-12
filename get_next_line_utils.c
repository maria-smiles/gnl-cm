//
// Created by Leann Alaskan on 5/25/21.
//
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char) c)
			return ((char *) &str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2, int endnul)
{
	char	*new_s;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new_s)
		return (NULL);
	new_s = ft_strdup(s1, endnul);
	i = len_s1;
	while (i < (len_s1 + len_s2))
	{
		new_s[i] = s2[i - len_s1];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

void	ft_strcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lensrc;

	if (!dst || !src)
		return ;
	lensrc = ft_strlen(src);
	if (lensrc == 0)
	{
		dst[0] = '\0';
		return ;
	}
	if (dstsize >= lensrc)
	{
		i = 0;
		while ((i < dstsize) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_strdup(const char *s1, int endnul)
{
	size_t	i;
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	i = 0;
	s2 = (char *) malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	if (endnul == 0)
		s2[i] = '\0';
	return (&s2[0]);
}
