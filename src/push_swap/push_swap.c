/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:55:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/22 16:31:58 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	verify(t_param *p, t_stack *s1, t_stack *s2)
{
	if (is_sorted(s1))
		return (1);
	if (lst_size(s1) == 1)
		return (1);
	if (lst_size(s1) == 2)
	{
		sort_two(s1);
		return (1);
	}
	if (lst_size(s1) == 3)
	{
		sort_three(s1);
		return (1);
	}
	else 
	{
		median_stack(p, s1);
		split_stack(p, s1, s2);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_param		p;
	t_stack		*s1;
	t_stack 	*s2;

	s1 = NULL;
	s2 = NULL;
	init(&p);
	if (ac == 1)
		return (0);
	while (--ac > 0)
	{
		if (ft_isnumber(av[ac]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		if (is_int(av[ac]) == 0)
		{
			printf("Error\n");
			return (0);
		}
		s1 = add_link(s1, ft_atoi(av[ac]));
	}
	verify(&p, s1, s2);
	return (0);
}
