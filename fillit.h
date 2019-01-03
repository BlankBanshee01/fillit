/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:22:14 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/12/29 02:26:03 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	point
{
	int			x;
	int			y;
}				coord;

typedef struct	tetrimonosa
{
		char	**data;
		char	id;
		coord	p[4];
}				tetri;

int				validity_manager(char *file);
void			cord_manager(char *file);
int				min_board_size(int nb);
void			solving(tetri **t, int size);
void			board_manager(tetri **t);
int				num_tetri(tetri **t);
void			printing_board(char **board);

int				put_one_tetri(int r, int d, tetri *t, char **board);
int				onevalid(int fd, int linenbr, char *av, int dznbr);
int				twovalid(int fd);
int				main(int argc, char **argv);
void			read_and_split(int fd, tetri **t);
void			proper_cord_manager(tetri **t);
char			**board(int nbr);
int				put_to_board(tetri **t, char **board, int nbr, int x);

#endif
