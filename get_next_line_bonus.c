/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <lramos-r@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 11:22:39 by lramos-r          #+#    #+#             */
/*   Updated: 2020/04/08 12:22:31 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static	char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(*dup) * len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static	void	ft_clear(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static	int		get_erro(int fd, int ret, char **str, char **line)
{
	int		erro;

	erro = 1;
	if (fd < 0 || ret < 0 || line == NULL || BUFFER_SIZE < 1 ||
			(read(fd, NULL, 0) < 0))
		erro = -1;
	else if (ret == 0 && str[fd] == NULL)
	{
		*line = ft_calloc(1, 1);
		erro = 0;
	}
	return (erro);
}

static	int		get_line(int fd, int ret, char **str, char **line)
{
	char	*aux;
	int		i;
	int		erro;

	if ((erro = get_erro(fd, ret, str, line)) < 1)
		return (erro);
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		aux = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = ft_strdup(aux);
		free(aux);
		if (str[fd][0] == '\0')
			ft_clear(&str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_clear(&str[fd]);
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	char			*buffer;
	char			*tmp;
	static char		*str[OPEN_MAX];

	if (!(buffer = (char *)malloc((sizeof(*buffer) * BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = ft_strdup(tmp);
			free(tmp);
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	ft_clear(&buffer);
	return (get_line(fd, ret, str, line));
}
