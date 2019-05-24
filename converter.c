/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:45:45 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/25 00:18:09 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_clr_buff(char *buf)
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

static int	ft_writer(char **str, char *buf)
{
	int		k;
	char	*test;

	k = 0;
	*str = ft_memalloc(1);
	while (++k < 5)
	{
		if (!(test = ft_strchrdup(buf, ENDL)))
			return (ERROR);
		if (!(*str = ft_strjoinfree(*str, test, 1)))
		{
			free(test);
			return (ERROR);
		}
		free(test);
		ft_clr_buff(buf);
	}
	return (SUCCESS);
}

int			ft_convert(char *buf, t_tet **fgrs)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	if (ft_writer(&str, buf) == ERROR)
		return (ERROR);
	while (str[i + 1] != '#')
		i++;
//	if (str[i + 3] == '#' && str[i - 1] != '.') // попытка создать if  для последней фигурки, которая должка выводиться как: ..#.###
//		i--;
	if(str[i + 3] == '#')
		i++;
	if (((str[i + 1] == '#') && (str[i + 4] == '#' \
	|| str[i + 8] == '#')) || str[i] == '#')
		i = i;
	else
		i++;
	j = i;
	while (str[++j])
		;
	while (str[--j] != '#')
		;
	if (!((*fgrs)->fig = ft_strsub(str, i, j - i + 1)))
		return (ERROR);
	printf("%s\n", (*fgrs)->fig);
	free((void *)str);
	return (SUCCESS);
}
