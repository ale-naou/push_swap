/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 12:41:10 by ale-naou          #+#    #+#             */
/*   Updated: 2016/03/06 13:25:33 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_args(t_env *e, int ac, char **av)
{
	e->i = e->color + e->stack_display;
	while (++e->i < ac)
	{
		e->j = -1;
		while (av[e->i][++e->j])
			if ((ft_isdigit(av[e->i][e->j]) == 0) && av[e->i][0] != '-') 
				error(1);
		e->k = e->i;
		while (++e->k < ac)
			if (ft_strcmp(av[e->k], av[e->i]) == 0)
				error(1); 
	}
}

static void	check_commands(t_env *e, int ac, char **av)
{
	while (++e->i < 3 && e->i < ac)
	{
		if (ft_strcmp(av[e->i], "-c") == 0)
			e->color = 1;
		else if (ft_strcmp(av[e->i], "-s") == 0)
			e->stack_display = 1;
	}
}

void		read_args(t_env *e, int ac, char **av)
{
	check_commands(e, ac, av);
	check_args(e, ac, av);
}
