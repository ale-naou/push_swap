/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:27:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/26 20:08:54 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_env *e)
{
	e->a_start = NULL;
	e->b_start = NULL;
	e->a_end = NULL;
	e->b_end = NULL;
	e->move_start = NULL;
}

int		main(int ac, char **av)
{
	t_env		e;
	t_struct	*current;
	int			i;

	init(&e);
	if (ac < 2)
	{
		ft_putendl("No enough args");
		return (-1);
	}
	i = 0;
	if (!(current = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	e.a_start = current;
	while (++i < ac)
	{
		current->n = ft_atoi(av[i]);
		current->next = NULL;
		if (i + 1 < ac)
		{
			if (!(current->next = (t_struct *)malloc(sizeof(t_struct))))
				return (-1);
			current = current->next;
		}
	}
	e.a_end = current;
	push_to_b(&e);
	push_to_b(&e);
	push_to_b(&e);
	push_to_b(&e);
	push_to_a(&e);
	rotate_both(&e);
	swap_a(&e);
	rotate_a(&e);
	swap_b(&e);
	rotate_b(&e);
	rev_rotate_a(&e);
	rev_rotate_b(&e);
	swap_b(&e);
	print_stack(&e);
	print_moves(&e);
	return (0);
}
