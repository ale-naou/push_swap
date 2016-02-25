/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 17:41:25 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/25 19:39:35 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_to_b(t_env *e)
{
	t_struct	*tmp;

	tmp = e->a_start;
	tmp->next = NULL;
	e->a_start = e->a_start->next;
	tmp->next = e->b_start;
	e->b_start = tmp;
}

void		push_to_a(t_env *e)
{

}
