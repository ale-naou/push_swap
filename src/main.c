/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:27:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/25 19:39:46 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_env		e;
	t_struct	*current;
	int			i;

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
	e.a_end->next = e.a_start;
	while (e.a_start != e.a_end)
	{
		ft_putnbr(e.a_start->n);
		e.a_start = e.a_start->next;
	}
	return (0);
}
