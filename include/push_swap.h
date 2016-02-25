/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:00:35 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/25 19:39:50 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/include/libft.h"

typedef struct		s_struct
{
	int				n;
	struct s_struct *next;
}					t_struct;

typedef struct		s_env
{
	t_struct	*a_start;
	t_struct	*b_start;
	t_struct	*a_end;
	t_struct	*b_end;
}					t_env;


/*
**	fonctions pushing from one line to another
*/

void		push_to_a(t_env *e);
void		push_to_b(t_env *e);

/*
**	fonctions swaping first and second element on a stack
*/

//void		swap_a(t_env *e);
//void		swap_b(t_env *e);
//void		swap_both(t_env *e);

/*
**	fontions putting first element to the bottom of a stack
*/

//void		rotate_a(t_env *e);
//void		rotate_b(t_env *e);
//void		rotate_both(t_env *e);

/*
**	fonctions putting last element to the top of a stack
*/

//void		rev_rotate_a(t_env *e);
//void		rev_rotate_b(t_env *e);
//void		rev_rotate_both(t_env *e);

#endif
