/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <lramos-r@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:43:09 by lramos-r          #+#    #+#             */
/*   Updated: 2020/04/07 11:43:36 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*join;
	int		len;
	int		i;
	int		j;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen((char *)str1) + ft_strlen((char *)str2);
	if (!(join = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		join[i] = str2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;
	int		i;

	len = ft_strlen((char *)str);
	if (!(dup = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
