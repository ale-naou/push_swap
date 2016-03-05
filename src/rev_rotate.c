/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:44:27 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 15:01:14 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_a(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	if (e->a_start != NULL && e->a_end != NULL)
	{
		tmp = e->a_end;
		tmp2 = e->a_start;
		while (tmp2->next != e->a_end)
			tmp2 = tmp2->next;
		e->a_end = tmp2;
		e->a_end->next = NULL;
		tmp->next = e->a_start;
		e->a_start = e->a_start->next;
		e->a_start = tmp;
		add_move(e, "rra");
	}
}

void		rev_rotate_b(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;


	if (e->b_start != NULL && e->b_end != NULL)
	{
		tmp = e->b_end;
		tmp2 = e->b_start;
		while (tmp2->next != e->b_end)
			tmp2 = tmp2->next;
		e->b_end = tmp2;
		e->b_end->next = NULL;
		tmp->next = e->b_start;
		e->b_start = e->b_start->next;
		e->b_start = tmp;
		add_move(e, "rrb");
	}
}

void		rev_rotate_both(t_env *e)
{
	t_struct	*tmp;
	t_struct	*tmp2;

	if ((e->a_start != NULL && e->a_end != NULL) ||
			(e->b_start != NULL && e->b_end))
	{
		tmp = e->a_end;
		tmp2 = e->a_start;
		while (tmp2->next != e->a_end)
			tmp2 = tmp2->next;
		e->a_end = tmp2;
		e->a_end->next = NULL;
		tmp->next = e->a_start;
		e->a_start = e->a_start->next;
		e->a_start = tmp;
		tmp = e->b_end;
		tmp2 = e->b_start;
		while (tmp2->next != e->b_end)
			tmp2 = tmp2->next;
		e->b_end = tmp2;
		e->b_end->next = NULL;
		tmp->next = e->b_start;
		e->b_start = e->b_start->next;
		e->b_start = tmp;
		add_move(e, "rrr");
	}
}
