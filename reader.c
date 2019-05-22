/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:19:59 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/22 17:20:02 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_list_write(t_tet **fgrs, char *buf, const char letr)
{
	int ct = -1;
	if (ft_check_valid(buf) == ERROR)
	{
		ft_remove_node(*fgrs);
		return (ERROR);
	}
	if (!*fgrs)
		*fgrs = ft_new_node(NULL, NULL, letr);
	else
	{
		(*fgrs)->next = ft_new_node(NULL, *fgrs, letr);
		(*fgrs) = (*fgrs)->next;
	}
	(*fgrs)->fig = ft_strsplit(ft_convert(buf, fgrs), '\n');
	printf("\n%p\n", *fgrs);
	while ((*fgrs)->fig[++ct])
	{
		ft_putstr((*fgrs)->fig[ct]);
		ft_putchar('\n');
	}
	return (SUCCESS);
}

static int	ft_file_check_n_read(t_tet **fgrs, int fd)
{
	int		status;
	char	letr;
	char	buf[21];

	letr = 'A' - 1;
	buf[0] = '\0';
	while ((status = read(fd, buf, FIGR)))
	{
		buf[status] = '\0';
		if (status == ERROR || ++letr > 'Z')
		{
			ft_remove_node(*fgrs);
			return (ERROR);
		}
		if (ft_list_write(fgrs, buf, letr) == ERROR)
			return (ERROR);
	}
	return ((buf[20] == '\n' || buf[0] == '\0') ? ERROR : SUCCESS);
}

int			ft_reader(const char *src, t_tet **fgrs, int argc)
{
	int	fd;
	int	status;

	if (argc != 2)
		return (INPUT_ERROR);
	if ((fd = open(src, O_RDONLY)) == -1)
		return (ERROR);
	status = ft_file_check_n_read(fgrs, fd);
	close(fd);
	return (status != ERROR ? SUCCESS : ERROR);
}
