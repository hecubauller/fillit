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

	if (!(new = (t_tet*)malloc(sizeof(t_tet))))
		return (NULL);
	new->let = letr;
	new->next = next;
	new->prev = prev;
	return (new);
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
		free((*fgrs)->fig);
		tmp = (*fgrs)->next;
		free(*fgrs);
		*fgrs = tmp;
	}
}
