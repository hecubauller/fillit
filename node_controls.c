/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:12:52 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/22 17:12:54 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*ft_new_node(t_tet *next, t_tet *prev, char letr)
{
	t_tet	*new;
	int		ct;

	ct = -1;
	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
//	if (!(new->fig = (char**)malloc(sizeof(char*) * 4)))
//	{
//		free(new);
//		return (NULL);
//	}
//	while (++ct < 4)
//		if (!(*(new->fig + ct) = (char*)malloc(sizeof(char) * 5)))
//		{
//			while (ct != -1)
//				free(new->fig[ct--]);
//			free(new);
//			return (NULL);
//		}
	new->x = 0;
	new->y = 0;
	new->let = letr;
	new->next = next;
	new->prev = prev;
	return (new);
}

void	ft_remove_node(t_tet *fgrs)
{
	int		ct;
	t_tet	*tmp;

	ct = -1;
	if (!fgrs)
		return ;
	while (fgrs)
	{
		while (++ct != 4)
			free(fgrs->fig[ct]);
		free(fgrs->fig);
		tmp = fgrs->next;
		free(fgrs);
		fgrs = fgrs->next;
	}
	fgrs = NULL;
}
