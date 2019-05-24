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

static void ft_clr_buff(char *buf)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (buf[j] && buf[j] != ENDL)
		j++;
	while (buf[++j])
		buf[++i] = buf[j];
	while (buf[j])
	{
		buf[j] = 0;
		j++;
	}
}

static int	ft_convert(char *buf, t_tet **fgrs)
{
	int i;
	int	k;
	int j;
	char *str;
	char *test;

	i = -1;
	k = 0;
	str = ft_memalloc(1);
	while(++k < 5)
	{
		test = ft_strchrdup(buf, ENDL);
		str = ft_strjoinfree(str, test, 1);
		free(test);
		ft_clr_buff(buf);
	}
	while (str[++i] && str[i + 1] != '#')
		;
	if (str[i + 1] == '#' && str[i + 5] == '#')
		i++;
	j = i;
	while (str[++j]);
	while (str[--j] != '#');
	if (!((*fgrs)->fig = ft_strsub(str, i, j - i + 1)))
		return (ERROR);
	free((void *)str);
	return (SUCCESS);

}

static int	ft_list_write(t_tet **fgrs, char *buf, const char letr)
{
	if (ft_check_valid(buf) == ERROR)
	{
		ft_remove_node(fgrs);
		return (ERROR);
	}
	if (!(*fgrs))
		*fgrs = ft_new_node(NULL, NULL, letr);
	else
	{
		(*fgrs)->next = ft_new_node(NULL, *fgrs, letr);
		*fgrs = (*fgrs)->next;
	}
	if (ft_convert(buf, fgrs) == ERROR)
	{
		ft_remove_node(fgrs);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	ft_file_check_n_read(t_tet **fgrs, int fd)
{
	int		status;
	char	letr;
	char	buf[21];

	letr = 'A' - 1;
	while ((status = read(fd, buf, FIGR)))
	{
		buf[status] = '\0';
		if (status == ERROR || ++letr > 'Z')
		{
			ft_remove_node(fgrs);
			return (ERROR);
		}
		if (ft_list_write(fgrs, buf, letr) == ERROR)
			return (ERROR);
	}
	return ((buf[0] == '\n' || buf[0] == '\0') ? ERROR : SUCCESS);
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
