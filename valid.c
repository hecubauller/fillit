/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/19 00:38:23 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

int			ft_check_n_write(int tet, char letr)
{
	while (!(tet & 0x8888))
		tet <<= 1;
	while (!(tet & 0xF000))
		tet <<= 4;
	if (tet == I_VERT || tet == I_EDGE || tet == J_VERT ||
		tet == J_R_ED || tet == J_L_ED || tet == J_UDWN ||
		tet == L_VERT || tet == L_R_ED || tet == L_L_ED ||
		tet == L_UDWN || tet == O_SING || tet == S_VERT ||
		tet == S_EDGE || tet == Z_VERT || tet == Z_EDGE ||
		tet == T_VERT || tet == T_R_ED || tet == T_L_ED ||
		tet == T_UDWN)
	{
		//ft_putstr("Valid!\n");
		if (letr == 'Z' + 1)
		{
			ft_putstr("error\n");
			return (-1);
		}
		return (1);
	}
	ft_putstr("error\n");
	return (-1);
}

int			ft_mr_translater(char *buf, int *tet, int ct2)
{

	int		ct;

	ct = -1;
	while (buf[++ct])
	{
		if (buf[ct] == '.')
			*tet = *tet << 1;
		else if (buf[ct] == '#')
			*tet = (*tet << 1) | 1;
		else
		{
			*tet = -1;
			break	;
		}
	}
	free(buf);
	if ((ct != 4) || (ct2 == 4 && !*tet))
		*tet = -1;
	return (*tet);
}

int			ft_tet_translate(int fd)
{
	int		tet;
	char	*buf;
	int		ct2;

	tet = 0;
	ct2 = 0;
	while (get_next_line(fd, &buf))
	{
		++ct2;
		if (!buf[0] && !ct2)
		{
			free(buf);
			return (-1);
		}
		if (!buf[0])
			break ;
		if (ft_mr_translater(buf, &tet, ct2) == -1)
			return (-1);
	}
	free(buf);
	return (ct2 != 4 && ct2 != 0 ? -1 : tet);
}

int			ft_check_valid(char **argv)
{
	int		fd;
	int		tet;
	char	letr;
	char	check_file[F_BUFF_SIZE];

	letr = 'A';
	fd = open(FILE, O_RDONLY);
	if (!(read(fd, check_file, F_BUFF_SIZE)))
	{
		ft_putstr("error\n");
		close(fd);
		return (0);
	}
	else
	{
		close(fd);
		fd = open(FILE, O_RDONLY);
	}
	while ((tet = ft_tet_translate(fd)) > 0)
		if ((ft_check_n_write(tet, letr++)) < 0)
			return (0);
	if (tet == -1)
		ft_putstr("error\n");
	close(fd);
	return (0);
}
