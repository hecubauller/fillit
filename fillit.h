/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:19 by ahiroko           #+#    #+#             */
/*   Updated: 2019/06/02 22:31:08 by huller           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

# define ENDL '\n'
# define FIGR 21

# define ERROR -1
# define INPUT_ERROR -2
# define SUCCESS 1

# define END 0

typedef struct		s_sol
{
	char			**matrix;
	int				line;
	int				cnt_x;
	int				cnt_y;
}					t_s;

typedef struct		s_cnt
{
	int				ct;
	int				dots;
	int				hashs;
	int				nw_lns;
	int				connections;
}					t_cnt;

typedef struct		s_cnv
{
	int				ct;
	int				i;
	int				i2;
	int				x_i;
	int				y_i;
}					t_cnv;

typedef struct		s_tet
{
	char			let;
	int				x[4];
	int				y[4];
	int				last_x;
	int				last_y;
	struct s_tet	*prev;
	struct s_tet	*next;
}					t_tet;

void				ft_remove_node(t_tet **fgrs);
t_tet				*ft_new_node(t_tet *next, t_tet *prev, char letr);
int					ft_check_valid(const char *buf);
int					ft_reader(const char *src, t_tet **fgrs, int argc);
int					ft_convert(char *buf, t_tet **fgrs);
char				**ft_solver(t_tet *fgrs, int size);
void				ft_get_first_fig(t_tet **fgrs);
char				**ft_new_matrix(int size, t_s *line);
void				ft_free_mtrx(t_s *line);
int					ft_mat_filler(t_tet *fgrs, t_s *slv);
void				ft_write_matrix(t_tet *fgrs, t_s *slv);
int					ft_write_check(t_tet *fgrs, t_s *slv);
int					ft_move_figures(t_tet *fgrs, t_s *slv);
int					ft_alg_slv(t_tet *fgrs, t_s *slv);
void				ft_resset_figures(t_tet *fgrs);
#endif
