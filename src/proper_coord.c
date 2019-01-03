/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proper_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:14 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:15 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	proper_cord_up(t_tetri **t, int k)
{
	int	i;
	int	j;
	int	r;

	r = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t[k]->data[i][j] == '#')
				break ;
			j++;
		}
		if (t[k]->data[i][j] == '#')
			break ;
		r++;
		i++;
	}
	return (r);
}

static int	proper_cord_left(t_tetri **t, int k)
{
	int	i;
	int	j;
	int	r;

	r = 0;
	j = 0;
	i = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 3)
		{
			if (t[k]->data[i][j] == '#')
				break ;
			i++;
		}
		if (t[k]->data[i][j] == '#')
		{
			break ;
		}
		r++;
		j++;
	}
	return (r);
}

void		proper_cord_manager(t_tetri **t)
{
	int		up;
	int		left;
	int		k;
	int		d;

	k = 0;
	while (t[k])
	{
		d = 0;
		up = proper_cord_up(t, k);
		left = proper_cord_left(t, k);
		while (d < 4)
		{
			t[k]->p[d].x = t[k]->p[d].x - left;
			t[k]->p[d].y = t[k]->p[d].y - up;
			d++;
		}
		k++;
	}
}
