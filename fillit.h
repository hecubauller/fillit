/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:19 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/19 16:06:24 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

# define    ENDL '\n'
# define    MAX_BUFF 546

typedef struct      s_cnt
{
	int             row;
	int             col;
}                   l_cnt;

typedef struct		s_tet
{
	char			fig;
	char			letter;
	int             x;
	int             y;
	char            *next;
}					l_tet;

int	ft_check_valid(char *argv, int argc);

#endif
