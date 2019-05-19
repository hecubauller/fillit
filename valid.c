/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/19 16:36:38 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     check_tets(char *buf, int fd)
{
	l_cnt cnt;
	char *temp;
	cnt.row = 0; // y
	cnt.col = 0; // x

	while(get_next_line(fd, &temp))
	{
		cnt.col = 0;
		while (temp[cnt.col] == '.' || temp[cnt.col] == '#')
			cnt.col++;
		cnt.row++;
		if (cnt.row == 4 && !*temp)
			cnt.row = 0;
		free(temp);
		if ((cnt.col != 4) || (cnt.row > 4))
			return (-1);
	}
	free(temp);
	return (cnt.row < 4 ? -1 : 1);
}

int    reader(char *src, char *buf)
{
	int     fd;
	int     cnt;
	int     res;

	cnt = 0;
	if ((fd = open(src, O_RDONLY)) == -1)
		return (-1);
	while ((res = read(fd, buf, MAX_BUFF)))
		if (++cnt >= 2)
			return (-1);
	close(fd);
	if ((fd = open(src, O_RDONLY)) == -1)
		return (-1);
	return (!*buf ? -1 : fd);
}

int			ft_check_valid(char *argv, int argc)
{
	int            fd;
	static char    buf[MAX_BUFF];

	if (argc != 2)
		return (-2);
	if ((fd = reader(argv, buf)) < 0)
		return (-1);
	if ((check_tets(buf, fd)) < 0)
		return (-1);

	return (0);
}
