#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if(!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t		i;
	char	*stack;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	stack = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (stack == NULL)
		return (NULL);
	while (i < len1)
	{
		*(stack + i) = *(s1 + i);
		i++;
	}
	free(s1);
	i = 0;
	while (i < len2)
	{
		*(stack + i + len1) = *(s2 + i);
		i++;
	}
	*(stack + i + len1) = '\0';
	return (stack);
}

char	*to_next(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

char	*to_line(char *buf)
{
	int		i;
	char	*s;

	i = 0;
	if (!buf)
		return (NULL);
	while (*(buf + (i)) != '\n' && *(buf + i) )
	{
		i++;
	}
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (*(buf + i) != '\n' && *(buf + i))
	{
		*(s + i) = *(buf + i);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}

int not_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while(*(str + i) != '\n')
	{
		if (*(str + i) == '\0')
			return (1);
		i++;
	}
	return (0);
}