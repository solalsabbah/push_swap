/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:55:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/26 21:37:44 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	verify(t_stack *s1)
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
	return (0);
}

int	call_functions(t_param *p, t_stack *s1, t_stack *s2)
{
	if (verify(s1) == 0)
	{
		median_stack(p, s1);
		split_stack(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
		split_second_stack(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
		bryan(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
		print_stack(s1, s2);
		split_first_stack(p, s1, s2);
	//	s1 = p->a1;
	//	s2 = p->b1;
	//	print_stack(s1, s2);
	} 
	return (1);
}

int	main(int ac, char **av)
{
	t_param		p;
	t_stack		*s1;
	t_stack		*s2;

	s1 = NULL;
	s2 = NULL;
	init(&p);
	if (ac == 1)
		return (0);
	while (--ac > 0)
	{
		if (ft_isnumber(av[ac]) == 0 || (is_int(av[ac]) == 0))
		{
			printf("Error\n");
			return (0);
		}
		s1 = add_link(s1, ft_atoi(av[ac]));
	}
	if (duplicated(s1) == 1)
		return (0);
	call_functions(&p, s1, s2);
	s1 = p.a1;
	s2 = p.b1;
//	print_stack(s1, s2);
	return (0);
}
