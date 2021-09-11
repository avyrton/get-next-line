#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define READ 1
# define READ_EOF 0
# define READ_ERROR -1

size_t	ft_strlen(const char *cad);
char	*ft_strjoin(char const *c1, char const *c2);
char	*ft_strchr(const char *cad, int n);
char	*ft_substr(char const *cad, unsigned int inic, size_t z);
char	*ft_strdup(const char *c1);
int		nulevoy(void **n, size_t z);
int		get_next_line(int fd, char **line);

#endif
