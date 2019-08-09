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

static int	ft_list_write(t_tet **fgrs, char *buf, const char let)
{
	if (ft_check_valid(buf) == ERROR)
	{
		ft_remove_node(fgrs);
		return (ERROR);
	}
	if (!(*fgrs))
		*fgrs = ft_new_node(NULL, NULL, let);
	else
	{
		(*fgrs)->next = ft_new_node(NULL, *fgrs, let);
		*fgrs = (*fgrs)->next;
	}
	ft_convert(buf, fgrs);
	return (SUCCESS);
}

static int	ft_file_check_n_read(t_tet **fgrs, int fd)
{
	int		status;
	char	let;
	char	buf[21];

	let = 'A' - 1;
	while ((status = read(fd, buf, FIGR)))
	{
		buf[status] = '\0';
		if (status == ERROR || ++let > 'Z')
		{
			ft_remove_node(fgrs);
			return (ERROR);
		}
		if (ft_list_write(fgrs, buf, let) == ERROR)
			return (ERROR);
	}
	return ((buf[0] == '\n' || buf[20] != '\0') ? ERROR : SUCCESS);
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
