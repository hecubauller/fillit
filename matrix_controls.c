/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huller <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:46:24 by huller            #+#    #+#             */
/*   Updated: 2019/06/02 20:30:38 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_free_mtrx(t_s *slv)
{
	int i;

	i = slv->line;
	while (i--)
	{
		free(slv->matrix[i]);
	}
	free(slv->matrix);
}

char				**ft_new_matrix(int size, t_s *slv)
{
	char	**matrix;
	int		y;

	y = -1;
	while (!(slv->line = ft_sqrt(size)))
		size++;
	if (!(matrix = (char**)malloc(sizeof(char*) * (slv->line + 1))))
		return (NULL);
	matrix[slv->line] = 0;
	while (++y < slv->line)
	{
		if (!(matrix[y] = (char*)malloc(sizeof(char) * (slv->line + 2))))
		{
			while (y > -1)
				free(matrix[y--]);
			free(matrix);
			return (NULL);
		}
		ft_memset(matrix[y], '.', slv->line);
		matrix[y][slv->line] = ENDL;
		matrix[y][slv->line + 1] = '\0';
	}
	return (matrix);
}
