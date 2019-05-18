/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:52:19 by ahiroko           #+#    #+#             */
/*   Updated: 2019/05/18 20:28:59 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "valid.h"

typedef struct		s_tet
{
	char			name;
	char			letter;
	char			used;
	int				code;
	struct s_tet	*next;
	struct s_tet	*prev;
}					l_tet;

int	ft_check_valid(char **argv);

#endif
