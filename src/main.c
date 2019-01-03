/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:38:59 by iet-tibi          #+#    #+#             */
/*   Updated: 2019/01/03 15:39:01 by iet-tibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage");
		return (0);
	}
	if (!(validity_manager(argv[1])))
	{
		ft_putstr("error");
		return (0);
	}
	cord_manager(argv[1]);
}
