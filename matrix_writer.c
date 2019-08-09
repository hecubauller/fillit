/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_writer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:38:23 by huller            #+#    #+#             */
/*   Updated: 2019/06/02 22:40:37 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_write_check(t_tet *fgrs, t_s *slv)
{
	if (slv->cnt_y + fgrs->y[3] < slv->line)
		return ((slv->matrix[slv->cnt_y + fgrs->y[0]]
		[slv->cnt_x + fgrs->x[0]] != '.' ||
		slv->matrix[slv->cnt_y + fgrs->y[1]]
		[slv->cnt_x + fgrs->x[1]] != '.' ||
		slv->matrix[slv->cnt_y + fgrs->y[2]]
		[slv->cnt_x + fgrs->x[2]] != '.' ||
		slv->matrix[slv->cnt_y + fgrs->y[3]]
		[slv->cnt_x + fgrs->x[3]] != '.') ? 0 : SUCCESS);
		return (ERROR);
}

void			ft_write_matrix(t_tet *fgrs, t_s *slv)
{
	fgrs->last_x = slv->cnt_x;
	fgrs->last_y = slv->cnt_y;
	slv->matrix[slv->cnt_y + fgrs->y[0]][slv->cnt_x + fgrs->x[0]] = fgrs->let;
	slv->matrix[slv->cnt_y + fgrs->y[1]][slv->cnt_x + fgrs->x[1]] = fgrs->let;
	slv->matrix[slv->cnt_y + fgrs->y[2]][slv->cnt_x + fgrs->x[2]] = fgrs->let;
	slv->matrix[slv->cnt_y + fgrs->y[3]][slv->cnt_x + fgrs->x[3]] = fgrs->let;
}

void			ft_remove_fig(t_tet *fgrs, t_s *slv)
{
	slv->matrix[fgrs->last_y + fgrs->y[0]][fgrs->last_x + fgrs->x[0]] = '.';
	slv->matrix[fgrs->last_y + fgrs->y[1]][fgrs->last_x + fgrs->x[1]] = '.';
	slv->matrix[fgrs->last_y + fgrs->y[2]][fgrs->last_x + fgrs->x[2]] = '.';
	slv->matrix[fgrs->last_y + fgrs->y[3]][fgrs->last_x + fgrs->x[3]] = '.';
}

int				ft_move_figures(t_tet *fgrs, t_s *slv)
{
	fgrs->last_x = 0;
	fgrs->last_y = 0;
	fgrs = fgrs->prev;
	if (fgrs == NULL)
		return (ERROR);
	ft_remove_fig(fgrs, slv);
	if (++fgrs->last_x == slv->line)
	{
		fgrs->last_y++;
		fgrs->last_x = 0;
	}
	return (2);
}

int				ft_mat_filler(t_tet *fgrs, t_s *slv)
{
	int status;

	slv->cnt_x = fgrs->last_x;
	slv->cnt_y = fgrs->last_y;
	while (!(status = ft_write_check(fgrs, slv)))
	{
		(slv->cnt_x)++;
		if (slv->cnt_x == slv->line)
		{
			slv->cnt_x = 0;
			(slv->cnt_y)++;
		}
	}
	if (status == ERROR)
		status = ft_move_figures(fgrs, slv);
	else if (status == SUCCESS)
		ft_write_matrix(fgrs, slv);
	if (status == 2)
		return (2);
	if (status == SUCCESS)
		return (SUCCESS);
	return (ERROR);
}
