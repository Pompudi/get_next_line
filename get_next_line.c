#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int 		byte;
	char		*buf;
	static char	*next_line;

	byte = 1;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	buf = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	while(byte != 0 && not_line(next_line))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buf);
			return (-1);
		}
		buf[byte] = '\0';
		next_line = ft_strjoin(next_line, buf);
	}
	free(buf);
	*line = to_line(next_line);
	next_line = to_next(next_line);
	if (byte == 0)
		return (0);
	return (1);
}