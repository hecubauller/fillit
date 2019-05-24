/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 20:47:45 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/24 20:47:48 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_cntcns_counter(const char *buf, int ct)
{
	int connections;

	connections = 0;
	if (buf[ct + 5] == '#')
		connections++;
	if (buf[ct - 5] == '#')
		connections++;
	if (buf[ct + 1] == '#')
		connections++;
	if (buf[ct - 1] == '#')
		connections++;
	return (connections);
}

int	ft_sym_counter(const char *buf)
{
	t_cnt valid;

	valid.ct = -1;
	valid.nw_lns = 0;
	valid.hashs = 0;
	valid.dots = 0;
	valid.connections = 0;
	if (buf[0] != '.' && buf[0] != '#')
		return (ERROR);
	while (buf[++valid.ct])
		if (buf[valid.ct] == '.')
			valid.dots++;
		else if (buf[valid.ct] == '#')
		{
			valid.hashs++;
			valid.connections += ft_cntcns_counter(buf, valid.ct);
		}
		else if (buf[valid.ct] == '\n')
			valid.nw_lns++;
		else
			return (ERROR);
	return (valid.connections >= 6 && valid.hashs == 4
	&& (valid.nw_lns >= 3 && valid.nw_lns <= 5) &&
	valid.dots == 12 ? SUCCESS : ERROR);
}

int	ft_check_valid(const char *buf)
{
	return (ft_sym_counter(buf) == SUCCESS ? SUCCESS : ERROR);
}
