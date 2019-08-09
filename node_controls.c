/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:12:52 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/31 22:38:45 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_first_fig(t_tet **fgrs)
{
	while ((*fgrs)->prev)
		*fgrs = (*fgrs)->prev;
}

t_tet	*ft_new_node(t_tet *next, t_tet *prev, char letr)
{
	t_tet	*new;

	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	new->last_x = 0;
	new->last_y = 0;
	new->let = letr;
	new->next = next;
	new->prev = prev;
	return (new);
}

void	ft_resset_figures(t_tet *fgrs)
{
	while (fgrs)
	{
		fgrs->last_x = 0;
		fgrs->last_y = 0;
		fgrs = fgrs->next;
	}
}

void	ft_remove_node(t_tet **fgrs)
{
	t_tet	*tmp;

	if (!*fgrs)
		return ;
	while ((*fgrs)->prev)
		*fgrs = (*fgrs)->prev;
	while (*fgrs)
	{
		tmp = (*fgrs)->next;
		free(*fgrs);
		*fgrs = tmp;
	}
}
