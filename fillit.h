/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:19 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/20 17:33:22 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

# define    ENDL '\n'
# define    MAX_BUFF 546

# define I_V_X 0
# define I_V_X 0123
# define I_E_X 0123
# define I_E_Y 0
/*	I figure values	*/

# define J_V_X 0001
# define J_V_y 0122
# define J_R_X 2012
# define J_R_Y 0111
# define J_L_X 0120
# define J_L_Y 0001
# define J_U_X 0111
# define J_U_Y 0012
/*	J figure values	*/

# define L_V_X 1101
# define L_V_Y 0122
# define L_R_X 0012
# define L_R_Y 0111
# define L_L_X 0122
# define L_L_Y 0001
# define L_U_X 0100
# define L_U_Y 0012
/* 	L figure values	*/

# define O_X 0101
# define O_Y 0111
/*	O figure values	*/

# define S_V_X
# define S_V_Y
# define S_E_X
# define S_E_Y
/*	S figure values	*/

# define T_V_X
# define T_V_Y
# define T_R_X
# define T_R_Y
# define T_L_X
# define T_L_Y
# define T_U_X
# define T_U_Y
/*	T figure values	*/

# define Z_V_X
# define Z_V_Y
# define Z_E_X
# define Z_E_Y
/*	Z figure values	*/



typedef struct      s_cnt
{
	int             row;
	int             col;
}                   l_cnt;

typedef struct		s_tet
{
	char			**fig;
	char			let;
	char             x;
	char             y;
	char            *next;
}					l_tet;

l_tet *ft_check_valid(char *argv, l_tet *fgrs);
l_tet *ft_new_node(char letr);

#endif