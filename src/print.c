/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-naou <ale-naou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:25:26 by ale-naou          #+#    #+#             */
/*   Updated: 2016/02/26 18:10:07 by ale-naou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_env *e)
{
	t_struct	*tmp;

	tmp = e->a_start;
	ft_putstr("A : ");
	while (tmp != NULL)
	{
		ft_putnbr(tmp->n);
		if (tmp->next == NULL)
		{
			ft_putchar('\n');
			break ;
		}
		ft_putchar(' ');
		tmp = tmp->next;
	}
	tmp = e->b_start;
	ft_putstr("B : ");
	while (tmp != NULL)
	{
		ft_putnbr(tmp->n);
		if (tmp->next == NULL)
		{
			ft_putchar('\n');
			break ;
		}
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
