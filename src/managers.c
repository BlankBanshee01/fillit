/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:07 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:08 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		num_tetri(t_tetri **t)
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
	t_tetri	**t;
	int		fd;

	t = malloc(sizeof(t_tetri*) * 27);
	fd = open(file, O_RDONLY);
	read_and_split(fd, t);
	proper_cord_manager(t);
	board_manager(t);
}

void	board_manager(t_tetri **t)
{
	int tet_nbr;

	tet_nbr = num_tetri(t);
	solving(t, min_board_size(tet_nbr));
}

void	solving(t_tetri **t, int size)
{
	char **boardd;

	boardd = board(size);
	if (!put_to_board(t, boardd, size, 0))
		return (solving(t, size + 1));
	printing_board(boardd);
}
