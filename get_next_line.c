#include "get_next_line.h"

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

static int	salida(char **save, char **line, int keep)
{
	if (keep < 0)
		return (-1);
	else if (keep == 0 && *save == NULL)
	{
		if (*save != NULL)
		{
			*line = ft_strdup(*save);
			free(*save);
			*save = NULL;
		}
		else
			*line = ft_strdup("");
		return (READ_EOF);
	}
	else
		return (annexlinelibreg(&*save, line));
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	int			keep;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (READ_ERROR);
	keep = 1;
	while (keep > 0)
	{
		keep = read(fd, buf, BUFFER_SIZE);
		if (keep >= 0)
			buf[keep] = '\0';
		if (keep <= 0)
			break ;
		if (save == NULL)
			save = ft_strdup(buf);
		else
			novyi_save(&save, buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (salida(&save, line, keep));
}
