/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:55:47 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/11/24 15:54:10 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putline(const int fd, char **line, char **stat)
{
	int i;

	i = 0;
	while (stat[fd][i] != '\n' && stat[fd][i] != '\0')
		i++;
	*line = ft_strsub(stat[fd], 0, i);
	if (stat[fd][i] == '\n')
		stat[fd] = ft_strdup(stat[fd] + i + 1);
	else if (stat[fd][i] == '\0')
		stat[fd] = ft_strnew(1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			re;
	static char *stat[4863];

	if (fd < 0 || line == NULL || fd > 4863 || BUFF_SIZE <= 0)
		return (-1);
	while ((re = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[re] = '\0';
		if (!stat[fd])
			stat[fd] = ft_strnew(1);
		stat[fd] = ft_strjoin(stat[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (re < 0)
		return (-1);
	else if (re == 0 && (stat[fd] == NULL || stat[fd][0] == '\0'))
		return (0);
	return (ft_putline(fd, line, stat));
}
