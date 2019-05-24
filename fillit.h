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
#include <stdio.h> ////////////////

# define ENDL '\n'
# define FIGR 21

# define ERROR -1
# define INPUT_ERROR -2
# define SUCCESS 1

typedef struct		s_cnt
{
	int				ct;
	int				dots;
	int				hashs;
	int				nw_lns;
	int				connections;
}					t_cnt;

typedef struct		s_tet
{
	char			*fig;
	char			let;
	int 			ind[4];
	struct s_tet	*prev;
	struct s_tet	*next;
}					t_tet;

void				ft_remove_node(t_tet **fgrs);
void				ft_get_first_figure(t_tet **fgrs);
t_tet				*ft_new_node(t_tet *next, t_tet *prev, char letr);
int					ft_check_valid(const char *buf);
int					ft_reader(const char *src, t_tet **fgrs, int argc);
char				*ft_solver(t_tet *fgrs);

#endif
