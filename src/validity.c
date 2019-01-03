/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:30 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:31 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		hash_num(char *line, int i, int dznbr)
{
	while (*line)
	{
		if (*line == '#')
			dznbr++;
		else if (*line != '.')
			return (0);
		line++;
		i++;
	}
	if (i != 4)
		return (5);
	return (dznbr);
}

int				onevalid(int fd, int linenbr, char *av, int dznbr)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line) > 0)
	{
		linenbr++;
		i = 0;
		if (!(linenbr % 5))
		{
			if (ft_strlen(line) != 0 || dznbr != 4)
			{
				return (0);
			}
			dznbr = 0;
			get_next_line(fd, &line);
			linenbr++;
		}
		dznbr = hash_num(line, i, dznbr);
	}
	close(fd);
	open(av, O_RDONLY);
	if (linenbr > 129 || dznbr != 4 || (linenbr + 1) % 5 != 0
			|| ((((linenbr + 1) / 5) * 21) - 1) != read(fd, line, 545))
		return (0);
	return (1);
}

int				relat_num(int count, int i, char *line)
{
	while (i < 21)
	{
		if (line[i] == '#')
		{
			if (i % 5 && line[i - 1] == '#')
				count++;
			if (i != 3 && i != 8 && i != 13 && i != 18 && line[i + 1] == '#')
				count++;
			if (i != 0 && i != 1 && i != 2 && i != 3 && line[i - 5] == '#')
				count++;
			if (i != 15 && i != 16 && i != 17 && i != 18 && line[i + 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

int				twovalid(int fd)
{
	int		i;
	int		count;
	char	line[21];

	count = 0;
	i = 0;
	while (read(fd, line, 21))
	{
		i = 0;
		count = relat_num(0, i, line);
		if ((count != 8 && count != 6))
			return (0);
	}
	return (1);
}
