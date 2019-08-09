/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:38:07 by ahiroko           #+#    #+#             */
/*   Updated: 2019/06/03 01:11:15 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_alg_slv(t_tet *fgrs, t_s *slv)
{
	int ct;
	int dots;
	int	res;

	ct = -1;
	res = 0;
	dots = 0;
	while (fgrs)
	{
		if ((res = ft_mat_filler(fgrs, slv)) == 2)
			fgrs = fgrs->prev;
		else if (res == SUCCESS)
			fgrs = fgrs->next;
		else if (res == ERROR)
			return (0);
	}
	return (1);
}

char	**ft_solver(t_tet *fgrs, int size)
{
	t_s slv;
	int status;
	int ct;

	ct = -1;
	if (!(slv.matrix = ft_new_matrix(size, &slv)))
		return (NULL);
	if (!(status = ft_alg_slv(fgrs, &slv)))
	{
		ft_free_mtrx(&slv);
		ft_resset_figures(fgrs);
		ft_solver(fgrs, (slv.line + 1) * (slv.line + 1));
	}
	if (status == 1)
	{
		while (++ct < slv.line)
			ft_putstr(slv.matrix[ct]);
		ft_free_mtrx(&slv);
	}
	return (slv.matrix);
}
