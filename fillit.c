/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:24 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/19 15:37:26 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int check;

	if ((check = ft_check_valid(argv[1], argc)) == -2)
		ft_putstr("usage: fillit filename\n");
	else if (check == -1)
		ft_putstr("error\n");
	return (0);
}
