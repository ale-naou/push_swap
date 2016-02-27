/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:27:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/27 20:40:34 by ale-naou         ###   ########.fr       */
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
	e->i = 0;
}

void	check_values_debug(t_env *e)
{
	print_stack(e);
	print_moves(e);
	ft_putstr("e->list_len : ");
	ft_putnbr(e->list_len);
	ft_putchar('\n');
	ft_putstr("e->list_med : ");
	ft_putnbr(e->list_med);
	ft_putchar('\n');
	ft_putstr("A sorted : ");
	ft_putnbr(a_sort(e));
	ft_putchar('\n');
	ft_putstr("B sorted : ");
	ft_putnbr(b_sort(e));
	ft_putchar('\n');
	ft_putstr("Stacks sorted : ");
	ft_putnbr(is_sort(e));
	ft_putchar('\n');
	ft_putendl("-------------------------------");
}

int		main(int ac, char **av)
{
	t_env		e;
	t_struct	*current;

	init(&e);
	if (ac < 2)
	{
		ft_putendl("No enough args");
		return (-1);
	}
	if (!(current = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	e.a_start = current;
	while (++e.i < ac)
	{
		current->n = ft_atoi(av[e.i]);
		current->next = NULL;
		if (e.i + 1 < ac)
		{
			if (!(current->next = (t_struct *)malloc(sizeof(t_struct))))
				return (-1);
			current = current->next;
		}
	}
	e.a_end = current;
	algo(&e);
	return (0);
}
