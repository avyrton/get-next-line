#include "get_next_line_bonus.h"

int	nulevoy(void **n, size_t z)
{
	*n = malloc(z);
	if (*n == NULL)
		return (0);
	return (1);
}

static void	novyi_save(char **save, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*save, buf);
	free(*save);
	*save = tmp;
}

static int	annexlinelibreg(char **guar, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while ((*guar)[len] != '\n' && (*guar)[len] != '\0')
		len++;
	if ((*guar)[len] == '\n')
	{
		*line = ft_substr(*guar, 0, len);
		tmp = ft_strdup(&((*guar)[len + 1]));
		free(*guar);
		*guar = tmp;
	}
	else
	{
		*line = ft_strdup(*guar);
		free(*guar);
		*guar = NULL;
		return (READ_EOF);
	}
	return (READ);
}

static int	salida(char **save, char **line, int keep, int fd)
{
	if (keep < 0)
		return (-1);
	else if (keep == 0 && save[fd] == NULL)
	{
		if (save[fd] != NULL)
		{
			*line = ft_strdup(save[fd]);
			free(save[fd]);
			save[fd] = NULL;
		}
		else
			*line = ft_strdup("");
		return (READ_EOF);
	}
	else
		return (annexlinelibreg(&save[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int			keep;
	static char	*save[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];

	keep = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (READ_ERROR);
	while (keep > 0)
	{
		keep = read(fd, buf, BUFFER_SIZE);
		if (keep >= 0)
			buf[keep] = '\0';
		if (keep <= 0)
			break ;
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buf);
		else
			novyi_save(&save[fd], buf);
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (salida(save, line, keep, fd));
}
