/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:43:04 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/05 14:50:52 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_env *e)
{
	int		tmp;

	if (e->a_start != NULL && e->a_start != NULL)
	{
		tmp = e->a_start->next->n;
		e->a_start->next->n = e->a_start->n;
		e->a_start->n = tmp;
		add_move(e, "sa");
	}
}

void		swap_b(t_env *e)
{
	int		tmp;

	if (e->b_start != NULL && e->b_start != NULL)
	{
		tmp = e->b_start->next->n;
		e->b_start->next->n = e->b_start->n;
		e->b_start->n = tmp;
		add_move(e, "sb");
	}
}

void		swap_both(t_env *e)
{
	int		tmp_a;
	int		tmp_b;


	if ((e->a_start != NULL && e->a_start->next != NULL) ||
			(e->b_start != NULL && e->b_start != NULL))
	{
		tmp_a = e->a_start->next->n;
		e->a_start->next->n = e->a_start->n;
		e->a_start->n = tmp_a;
		tmp_b = e->b_start->next->n;
		e->b_start->next->n = e->b_start->n;
		e->b_start->n = tmp_b;
		add_move(e, "ss");
	}
}
