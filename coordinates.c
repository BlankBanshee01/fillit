/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:58:27 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/12/29 02:15:39 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	get_cord(tetri **t, int b)
{
	int		i;
	int		j;
	int		r;
	int		k;

	i = 0;
	k = 0;
	r = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t[b]->data[i][j] == '#')
			{
				t[b]->p[r].x = j;
				t[b]->p[r].y = i;
				r++;
			}
			j++;
		}
		i++;
	}
}

static void	rita_skita(tetri **t, char *buff)
{
	static char	a;
	static int	i;

	if (!a && !i)
	{
		a = 'A';
		i = 0;
	}
	t[i] = malloc(sizeof(tetri));
	t[i]->data = ft_strsplit(buff, '\n');
	t[i]->id = a++;
	get_cord(t, i);
	i++;
	t[i] = NULL;
}

void		read_and_split(int fd, tetri **t)
{
	char	*line;
	char	*buff;
	int		l;

	l = 0;
	buff = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		l++;
		if (l <= 4)
		{
			buff = ft_strjoin(buff, line);
			buff = ft_strjoin(buff, "\n");
		}
		if (l > 4)
		{
			rita_skita(t, buff);
			l = 0;
			buff = ft_strnew(0);
		}
	}
	rita_skita(t, buff);
}
