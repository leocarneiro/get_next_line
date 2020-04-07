/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r </var/mail/lramos-r>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:43:55 by lramos-r          #+#    #+#             */
/*   Updated: 2020/04/07 11:46:14 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int			get_next_line(int fd, char **line);
char		*ft_strnew(int len);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *str1, char const *str2);
char		*ft_strdup(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif
