#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char *to_line(char *buf);
char	*to_next(char *save);
int not_line(char *str);

#endif
