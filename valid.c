/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/20 16:56:34 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


l_tet   *scan_figs(char *str, l_tet *fgr)
{
	int

	char   **tmp;
	char    *buf;

	while (str[x])
	{
		while (str[x] == '.' && str[x + 1] != '#')
			x++;
		if (str[x] != '.' && str[x] != '\0')
			return (-1);
		while (str[x])
			buf[x][y] = str[x];
		y++;
		free((void *)str);
	}
	free((void *)str);
	if (ft_check_connections(str))


	return(NULL);
}








int     check_tets(int fd)
{
	l_cnt cnt;
	char *temp;
	cnt.row = 0;
	cnt.col = 0;

	while(get_next_line(fd, &temp))
	{
		cnt.col = 0;
		while (temp[cnt.col] == '.' || temp[cnt.col] == '#')
			cnt.col++;
		if (temp[cnt.col] != '.' && temp[cnt.col] != '#' && temp[cnt.col])
			return (-1);
		cnt.row++;
		if (cnt.row == 5 && !*temp)
			cnt.row = 0;
		free(temp);
		if (((cnt.col != 4) || (cnt.row >= 5)) && (*temp))
			return (-1);
		else if (cnt.row > 0 && !*temp)
			return (-1);
	}
	free(temp);
	return (cnt.row < 4 ? -1 : 1);
}

int    reader(char *src, char *buf)
{
	int     fd;
	int     cnt;

	cnt = 0;
	if ((fd = open(src, O_RDONLY)) == -1)
		return (-1);
	while ((read(fd, buf, MAX_BUFF)))
		if (++cnt >= 2)
			return (-1);
	close(fd);
	if ((fd = open(src, O_RDONLY)) == -1)
		return (-1);
	return (!*buf ? -1 : fd);
}

l_tet		*ft_check_valid(char *argv, l_tet *fgrs)
{
	int            fd;
	static char    buf[MAX_BUFF];

	if ((fd = reader(argv, buf)) < 0)
		return (NULL);
	if (check_tets(fd) < 0)
		return (NULL);
	return (scan_figs(buf, fgrs) == NULL ? NULL : fgrs);
}
