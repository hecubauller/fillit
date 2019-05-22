/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:24 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/20 16:04:31 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tet	*fgrs;
	int		status;

	if ((status = ft_reader(argv[1], &fgrs, argc)) != SUCCESS)
	{
		ft_putstr(status != ERROR ? "usage: fillit filename\n" : "error\n");
		return (0);
	}


	return (0);
}
