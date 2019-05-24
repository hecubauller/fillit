/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:38:07 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/24 17:38:09 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char 	*ft_solver(t_tet *fgrs)
{
	char 	*matrix;
	int i;

	i = (fgrs->let - '@') * 4;
	while(!ft_sqrt(i))
		i++;
	matrix = ft_strnew(i);
	ft_memset(matrix, '.', i);
	return (NULL);
}
