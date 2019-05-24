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

void	ft_add_ind(t_tet **fgrs)
{
	int i;
	int j;
	t_tet *tmp;

	tmp = NULL;
	while (*fgrs)
	{
		j = -1;
		i = -1;
		while ((*fgrs)->fig[++i])
		{
			if ((*fgrs)->fig[i] == '#')
				(*fgrs)->ind[++j] = i;
		}
		tmp = *fgrs;
		*fgrs = (*fgrs)->prev;
	}
	*fgrs = tmp;
}

int		main(int argc, char **argv)
{
	t_tet	*fgrs;
	int		status;

	fgrs = NULL;
	if ((status = ft_reader(argv[1], &fgrs, argc)) != SUCCESS)
	{
		ft_putstr(status != ERROR ? "usage: fillit filename\n" : "error\n");
		return (0);
	}
	ft_add_ind(&fgrs);
	ft_solver(fgrs);
	return (0);
}
