/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <lramos-r@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 11:22:39 by lramos-r          #+#    #+#             */
/*   Updated: 2020/04/06 11:23:08 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnew(int len)
{
	char	*new;

	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (len >= 0)
	{
		*new = '\0';
		len--;
		new++;
	}
	return (new);
}

void	ft_clear(char *str)
{
	free(str);
	str = ft_strnew(1);
}

int		get_erro(int fd, int ret, char **str, char **line)
{
	int		erro;

	erro = 1;
	if (fd < 0 || ret < 0 || line == NULL || BUFFER_SIZE < 1 || \
		(read(fd, NULL, 0) < 0))
		erro = -1;
	else if (ret == 0 && str[fd] == NULL)
	{
		*line = ft_strnew(1);
		erro = 0;
	}
	return (erro);
}

int		get_line(int fd, int ret, char **str, char **line)
{
	char	*aux;
	int		i;
	int		erro;

	if ((erro = get_erro(fd, ret, str, line)) < 1)
		return (erro);
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	if (str[fd][i] == '\n')
	{
		*line = ft_substr(str[fd], 0, i);
		aux = ft_strdup(&str[fd][i + 1]);
		ft_clear(str[fd]);
		str[fd] = ft_strdup(aux);
		if (str[fd][0] == '\0')
			ft_clear(str[fd]);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_clear(str[fd]);
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*buffer;
	char			*tmp;
	static char		*str[OPEN_MAX];

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str[fd], buffer);
			ft_clear(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	ft_clear(buffer);
	return (get_line(fd, ret, str, line));
}
