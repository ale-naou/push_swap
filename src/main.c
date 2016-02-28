/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:27:42 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/28 19:46:34 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	init(t_env *e)
{
	e->a_start = NULL;
	e->b_start = NULL;
	e->a_end = NULL;
	e->b_end = NULL;
	e->move_start = NULL;
	e->color_switch = 0;
	e->everymove_switch = 0;
}

static void	aff_help(void)
{
	ft_putchar('	');
	ft_putendl("Usage	: ./push_swap [-c] [-v] Arguments list.");
	ft_putchar('	');
	ft_putendl("[-c]	: Add color on moves.");
	ft_putchar('	');
	ft_putendl("[-s]	: Display stacks state after every move.");
	exit(0);
}

static int	create_list(t_env *e, int ac, char **av)
{
	t_struct	*current;

	e->i = e->color_switch + e->everymove_switch;
	if (!(current = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	e->a_start = current;
	while (++e->i < ac)
	{
		current->n = ft_atoi(av[e->i]);
		current->next = NULL;
		if (e->i + 1 < ac)
		{
			if (!(current->next = (t_struct *)malloc(sizeof(t_struct))))
				return (-1);
			current = current->next;
		}
	}
	e->a_end = current;
	return (0);
}

static void	read_args(t_env *e, int ac, char **av)
{
	e->i = 0;
	while (++e->i < ac)
	{
		e->j = -1;
		while (++e->j != 0)
		{
			if ((av[e->i][e->j] >= '0' && av[e->i][e->j] <= 9) || 
				(av[e->i][e->j] == '-' && av[e->i][e->j] == '+') || 
				(av[e->i][e->j] == '-' &&
				(av[e->i][e->j + 1] == 'c' || av[e->i][e->j + 1] == 's')))
			{	
				if (ft_strcmp(av[e->i], "-c") == 0)
					e->color_switch = 1;
				if (ft_strcmp(av[e->i], "-s") == 0)
					e->everymove_switch = 1;
			}
			else
				error(1);
		}

	}
}

int			main(int ac, char **av)
{
	t_env		e;

	if (ac > 2)
	{
		if (ft_strcmp(av[1], "-help") == 0)
			aff_help();
		init(&e);
		read_args(&e, ac, av);
		create_list(&e, ac, av);
		algo(&e);
	}
	else
		aff_help();
	return (0);
}
