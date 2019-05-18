/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:17 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/18 20:41:32 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

# include <fcntl.h>
# include "get_next_line.h"
# include "fillit.h"

# define TEST_BUF_CNT ft_putstr("\033[1;33m"); ft_putstr(buf); ft_putstr("\n\033[0m")
# define TEST_TET_NBR ft_putstr("\nTet: \033[1;36m"); ft_putnbr(tet); ft_putstr("\033[0m"); ft_putchar('\n')
# define TEST_TET_NBR2 ft_putstr("\nTet2: \033[1;36m"); ft_putnbr(node->code); ft_putstr("\033[0m"); ft_putchar('\n')

# define FILE argv[1]
# define F_BUFF_SIZE 546

# define I_VERT 0x8888 			//1000 1000 1000 1000	//34952
# define I_EDGE 0xF000			//1111 0000 0000 0000	//61440
/*	I figure values	*/

# define J_VERT 0x44C0			//0100 0100 1100 0000	//17600
# define J_R_ED 0x8E00			//1000 1110 0000 0000	//36352
# define J_L_ED 0xE200			//1110 0010 0000 0000	//57856
# define J_UDWN 0xC880			//1100 1000 1000 0000	//51328
/*	J figure values	*/

# define L_VERT 0x44C0			//0100 0100 1100 0000	//17600
# define L_R_ED 0xE800			//1110 1000 0000 0000	//59392
# define L_L_ED 0x2E00			//0010 1110 0000 0000	//11776
# define L_UDWN 0xC440			//1100 0100 0100 0000	//50240
/* 	L figure values	*/

# define O_SING 0xCC00			//1100 1100 0000 0000	//52224
/*	O figure values	*/

# define S_VERT 0x6C00			//0110 1100 0000 0000	//27648
# define S_EDGE 0x8C40			//1000 1100 0100 0000	//35904
/*	S figure values	*/

# define T_VERT 0x4E00			//0100 1110 0000 0000	//19968
# define T_R_ED 0x8C80			//1000 1100 1000 0000	//35968
# define T_L_ED 0x4C40			//0100 1100 0100 0000	//19520
# define T_UDWN 0xE400			//1110 0100 0000 0000	//58368
/*	T figure values	*/

# define Z_VERT 0xC600			//1100 0110 0000 0000	//50688
# define Z_EDGE 0x4C80			//0100 1100 1000 0000	//19584
/*	Z figure values	*/

/*
**		*_VERT - vertical
**		*_EDGE - edge
**		*_SING - single
**		*_R_ED - right edge
**		*_L_ED - left edge
**		*_UDWN - upside down
*/

# define ERROR -1
# define SUCCESS 1


#endif
