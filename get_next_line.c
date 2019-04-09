/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asansyzb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 21:38:11 by asansyzb          #+#    #+#             */
/*   Updated: 2019/04/08 21:38:12 by asansyzb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*c[127];
	char		buff[BUFF_SIZE + 1];
	int			i;
	char		*endl;
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE < 1
			|| (!c[fd] && !(c[fd] = ft_strnew(1))))
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		c[fd] = ft_strupd(c[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (i == -1 || !*(tmp = c[fd]))
		return (i == -1 ? -1 : 0);
	endl = ft_strchr(c[fd], '\n');
	*line = (endl) ?
		ft_strndup(c[fd], endl - c[fd]) : ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + (endl ? 1 : 0)),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + (endl ? 1 : 0))));
	ft_strdel(&tmp);
	return (!(!c[fd] && !ft_strlen(*line)));
}
