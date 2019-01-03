/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:00:50 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/12/29 02:16:32 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		num_tetri(tetri **t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}

int		validity_manager(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (onevalid(fd, 0, file, 0))
	{
		fd = open(file, O_RDONLY);
		if (twovalid(fd))
			return (1);
	}
	return (0);
}

void	cord_manager(char *file)
{
	tetri	**t;
	int		fd;

	t = malloc(sizeof(tetri*) * 27);
	fd = open(file, O_RDONLY);
	read_and_split(fd, t);
	proper_cord_manager(t);
	board_manager(t);
}

void	board_manager(tetri **t)
{
	int tet_nbr;

	tet_nbr = num_tetri(t);
	solving(t, min_board_size(tet_nbr));
}

void	solving(tetri **t, int size)
{
	char **boardd;

	boardd = board(size);
	if (!put_to_board(t, boardd, size, 0))
		return (solving(t, size + 1));
	printing_board(boardd);
}
