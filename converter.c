/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:45:45 by ahiroko           #+#    #+#             */
/*   Updated: 2019/06/02 20:28:43 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_move(t_tet **fgrs)
{
	int ct;
	int ct2;
	int res_x;
	int res_y;

	ct = -1;
	ct2 = -1;
	res_x = 4;
	res_y = 4;
	while (++ct < 4)
	{
		if (res_x > (*fgrs)->x[ct])
			res_x = (*fgrs)->x[ct];
		if (res_y > (*fgrs)->y[ct])
			res_y = (*fgrs)->y[ct];
	}
	while (--ct > -1)
	{
		(*fgrs)->x[ct] -= res_x;
		(*fgrs)->y[ct] -= res_y;
	}
}

int			ft_convert(char *buf, t_tet **fgrs)
{
	t_cnv	conv;

	conv.ct = -1;
	conv.i = -1;
	conv.i2 = 0;
	conv.x_i = 0;
	conv.y_i = 0;
	while (++conv.ct < 20)
	{
		conv.i++;
		if (buf[conv.ct] == ENDL)
		{
			conv.i = -1;
			conv.i2++;
		}
		if (buf[conv.ct] == '#')
		{
			(*fgrs)->x[conv.x_i++] = conv.i;
			(*fgrs)->y[conv.y_i++] = conv.i2;
		}
	}
	ft_move(fgrs);
	return (SUCCESS);
}
