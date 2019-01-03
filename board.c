/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 01:44:44 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/12/29 02:16:04 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_board_size(int nb)
{
	int		racine;

	racine = 0;
	if (nb < 0)
		return (0);
	while ((racine * racine) < nb)
		racine++;
	if ((racine * racine) == nb)
		return (racine);
	return (racine);
}

void	init_board(char **board, int dimention)
{
	int	i;
	int	j;

	i = 0;
	while (i < dimention)
	{
		j = 0;
		while (j < dimention)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
}

char	**board(int dimention)
{
	int		i;
	char	**grid;

	i = 0;
	grid = (char **)malloc(sizeof(char *) * (dimention + 1));
	while (i < dimention)
	{
		grid[i] = (char *)malloc(sizeof(char) * (dimention + 1));
		grid[i][dimention] = '\0';
		i++;
	}
	grid[dimention] = 0;
	init_board(grid, dimention);
	return (grid);
}

void	printing_board(char **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		ft_putstr(board[i++]);
		ft_putchar('\n');
	}
}
