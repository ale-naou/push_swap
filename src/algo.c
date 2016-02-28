/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 14:07:31 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/28 19:46:36 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	def_min_max(t_env *e)
{
	t_struct	*tmp;

	e->i = 1;
	tmp = e->a_start;
	while (tmp != NULL)
	{
		e->i == 1 ? e->list_min = tmp->n : 0;
		e->i == 1 ? e->list_max = tmp->n : 0;
		tmp->n < e->list_min ? e->list_min = tmp->n : 0;
		tmp->n > e->list_max ? e->list_max = tmp->n : 0;
		e->i++;
		tmp = tmp->next;
	}
	e->list_len = e->i - 1;
	e->list_med = e->i / 2;
	e->i = 1;
	tmp = e->a_start;
	while (tmp != NULL && tmp->n != e->list_min)
	{
		e->i++;
		tmp = tmp->next;
	}
	e->pos_min = e->i;
}

void		algo(t_env *e)
{
	e->i = 0;
	while (is_sort(e) != 3 || e->b_start != NULL)
	{
		def_min_max(e);
		check_values_debug(e);
		if (e->list_len == 3)
			e->list_max == e->a_start->n ? rotate_a(e) : 0;
		if (e->list_min == e->a_start->next->n)
			swap_a(e);
		else
		{
			while (e->a_start->n != e->list_min)
			{
				if (e->pos_min < e->list_med)
					rotate_a(e);
				else
					rev_rotate_a(e);
			}
		}
		if (is_sort(e) != 3)
			push_to_b(e);
		if (is_sort(e) == 3)
			while (e->b_start != NULL)
				push_to_a(e);
	}
	def_min_max(e);
	check_values_debug(e);
}
