/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iet-tibi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:03:06 by iet-tibi          #+#    #+#             */
/*   Updated: 2018/12/29 02:17:25 by iet-tibi         ###   ########.fr       */
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
