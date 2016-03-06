/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:00:35 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/06 13:25:31 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../lib/include/libft.h"

typedef	struct		s_moves
{
	char 			*str;
	struct s_moves	*next;
}					t_moves;

typedef struct		s_struct
{
	int				n;
	struct s_struct *next;
}					t_struct;

typedef struct		s_env
{
	t_struct		*a_start;
	t_struct		*b_start;
	t_struct		*a_end;
	t_struct		*b_end;
	t_moves			*move_start;
	t_moves			*move_end;
	
	int				list_len;
	int				list_med;
	int				list_min;
	int				list_max;
	int				pos_min;
	int				i;
	int				j;
	int				k;
	int				color;
	int				stack_display;
}					t_env;


/*
**	fonctions pushing from one line to another
*/

void		push_to_a(t_env *e);
void		push_to_b(t_env *e);

/*
**	fonctions swaping first and second element on a stack
*/

void		swap_a(t_env *e);
void		swap_b(t_env *e);
void		swap_both(t_env *e);

/*
**	fontions putting first element to the bottom of a stack
*/

void		rotate_a(t_env *e);
void		rotate_b(t_env *e);
void		rotate_both(t_env *e);

/*
**	fonctions putting last element to the top of a stack
*/

void		rev_rotate_a(t_env *e);
void		rev_rotate_b(t_env *e);
void		rev_rotate_both(t_env *e);


/*
**	fonctions checking stacks sorting
*/

int			is_sort(t_env *e);
int			a_sort(t_env *e);
int			b_sort(t_env *e);

/*
**	Display fonctions
*/

void		print_stack(t_env *e);
void		print_moves(t_env *e);
void		add_move(t_env *e, char *str);


void		algo(t_env *e);
void		sort_last(t_env *e);


void		read_args(t_env *e, int ac, char **av);
void		error(int c);
void		check_values_debug(t_env *e);
#endif
