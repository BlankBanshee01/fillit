/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:39:23 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:25 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tetri(char **board, char wanted)
{
	int	i;
	int	j;

	i = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == wanted)
				board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		put_one_tetri(int r, int d, t_tetri *t, char **board)
{
	int i;
	int dimention;

	i = 0;
	dimention = ft_strlen(board[0]);
	while (i < 4 && ((t->p[i].y + d) < dimention) &&
			((t->p[i].x + r) < dimention))
	{
		board[d + t->p[i].y][r + t->p[i].x] = t->id;
		i++;
	}
	if (i != 4)
		return (0);
	else
		return (1);
}

int		it_fits_it_sits(int r, int d, t_tetri *t, char **board)
{
	int	i;
	int	dimention;

	i = 0;
	dimention = ft_strlen(board[0]);
	while (i < 4 && ((t->p[i].y + d) < dimention) && ((t->p[i].x + r)
				< dimention) && board[d + t->p[i].y][r + t->p[i].x] == '.')
		i++;
	if (i != 4)
		return (0);
	else
		return (1);
}

int		put_to_board(t_tetri **t, char **board, int dimention, int x)
{
	int tab[2];

	tab[0] = 0;
	tab[1] = 0;
	if (x == num_tetri(t))
		return (1);
	while (tab[0] < dimention)
	{
		while (tab[1] < dimention)
		{
			if (it_fits_it_sits(tab[1], tab[0], t[x], board))
			{
				put_one_tetri(tab[1], tab[0], t[x], board);
				if ((put_to_board(t, board, dimention, x + 1)) == 1)
					return (1);
				else
					remove_tetri(board, t[x]->id);
			}
			tab[1]++;
		}
		tab[1] = 0;
		tab[0]++;
	}
	x++;
	return (0);
}
