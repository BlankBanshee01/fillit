/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:38:51 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/01/03 16:32:42 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetrimonosa
{
	char			**data;
	char			id;
	t_coord			p[4];
}					t_tetri;

int					validity_manager(char *file);
void				cord_manager(char *file);
int					min_board_size(int nb);
void				solving(t_tetri **t, int size);
void				board_manager(t_tetri **t);
int					num_tetri(t_tetri **t);
void				printing_board(char **board);
int					put_one_tetri(int r, int d, t_tetri *t, char **board);
int					onevalid(int fd, int linenbr, char *av, int dznbr);
int					twovalid(int fd);
int					main(int argc, char **argv);
void				read_and_split(int fd, t_tetri **t);
void				proper_cord_manager(t_tetri **t);
char				**board(int nbr);
int					put_to_board(t_tetri **t, char **board, int nbr, int x);

#endif
