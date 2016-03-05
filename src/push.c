/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:41:25 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 15:31:07 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_b(t_env *e)
{
	t_struct	*tmp;

	if (e->a_start != NULL)
	{
		tmp = e->a_start;
		e->a_start = e->a_start->next;
		if (e->b_end == NULL)
			e->b_end = tmp;
		tmp->next = e->b_start;
		e->b_start = tmp;
		add_move(e, "pb");
	}
}

void		push_to_a(t_env *e)
{
	t_struct	*tmp;

	if (e->b_start != NULL)
	{
		tmp = e->b_start;
		e->b_start = e->b_start->next;
		tmp->next = e->a_start;
		e->a_start = tmp;
		add_move(e, "pa");
	}
}
