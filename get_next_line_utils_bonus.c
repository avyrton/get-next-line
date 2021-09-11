#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *cad)
{
	size_t	k;

	k = 0;
	if (*cad == '\0')
		return (0);
	while (cad[k])
		k++;
	return (k);
}

char	*ft_strjoin(char const *c1, char const *c2)
{
	char	*destino;
	size_t	i;
	size_t	lngt;

	destino = NULL;
	i = 0;
	if (!c1 || !c2)
		return (NULL);
	lngt = ft_strlen(c1) + ft_strlen(c2);
	if (!(nulevoy((void **)&destino, sizeof(char) * lngt + 1)))
		return (NULL);
	while (c1[i])
	{
		destino[i] = c1[i];
		i++;
	}
	while (i < lngt)
	{
		destino[i] = *(c2)++;
		i++;
	}
	destino[i] = '\0';
	return (destino);
}

char	*ft_strdup(char const *cad)
{
	int		len;
	int		i;
	char	*destino;

	len = 0;
	i = 0;
	while (cad[len])
		len++;
	if (!(nulevoy((void **)&destino, sizeof(char) * len + 1)))
		return (NULL);
	while (cad[i])
	{
		destino[i] = cad[i];
		i++;
	}
	destino[i] = '\0';
	return (destino);
}

char	*ft_strchr(char const *cad, int n)
{
	size_t	i;
	size_t	lngt;

	i = 0;
	lngt = ft_strlen(cad) + 1;
	while (i < lngt)
	{
		if (((unsigned char *)cad)[i] == (unsigned char)n)
		{
			return (&((char *)cad)[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *cad, unsigned int inic, size_t z)
{
	char	*subcad;
	size_t	i;
	size_t	lenc;

	i = 0;
	if (!cad)
		return (NULL);
	lenc = ft_strlen(cad);
	if (inic >= lenc)
	{
		if (!(nulevoy((void **)&subcad, sizeof(char) * 1)))
			return (NULL);
		*subcad = '\0';
		return (subcad);
	}
	if (!(nulevoy((void **)&subcad, sizeof(char) * z + 1)))
		return (NULL);
	while (i < z)
	{
		subcad[i] = cad[inic + i];
		i++;
	}
	subcad[i] = '\0';
	return (subcad);
}
