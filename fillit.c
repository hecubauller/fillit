/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:24 by ahiroko           #+#    #+#             */
/*   Updated: 2019/06/02 19:47:33 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tet	*fgrs;
	int		status;
	int		ct;
	int		min_size;
	char	**answer;

	fgrs = NULL;
	if ((status = ft_reader(argv[1], &fgrs, argc)) != SUCCESS)
	{
		ft_putstr(status != ERROR ? "usage: fillit filename\n" : "error\n");
		return (0);
	}
	min_size = (fgrs->let - '@') * 4;
	ft_get_first_fig(&fgrs);
	if (!(answer = ft_solver(fgrs, min_size)))
	{
		ft_putstr("error\n");
		ft_remove_node(&fgrs);
		return (0);
	}
	ct = -1;
	ft_remove_node(&fgrs);
	return (0);
}
