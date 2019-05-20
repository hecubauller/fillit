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

l_tet *ft_new_node(char letr)
{
	l_tet *new;
	int ct;

	ct = -1;
	if (!(new = (l_tet*)malloc(sizeof(l_tet))))
		return (NULL);
	if (!(new->fig = (char**)malloc(sizeof(char*) * 4)))
	{
		free(new);
		return (NULL);
	}
	while (++ct < 4)
		if (!(*(new->fig + ct) = (char*)malloc(sizeof(char) * 5)))
		{
			while (ct != -1)
				free (new->fig[ct--]);
			free(new);
			return (NULL);
		}
	new->x = 0;
	new->y = 0;
	new->let = letr;
	new->next = NULL;
	return (new);
}

int		main(int argc, char **argv)
{
	l_tet *fgrs;

	if (argc != 2)
	{
		ft_putstr("usage: fillit filename\n");
		return (0);
	}

	if ((fgrs = ft_check_valid(*argv, fgrs)) == NULL)
		ft_putstr("error\n");
	return (0);
}
