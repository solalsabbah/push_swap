/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:55:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 16:54:03 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	set_med(t_stack *s, int med)
{
	while (s)
	{
		s->med = med;
		s = s->next;
	}
}

int		verify(t_stack *s1)
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

void	conditions_functions(t_param *p, t_stack *s1, t_stack *s2)
{
	if (lst_size(s2) > 30)
	{
		split_second_stack(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	bryan(p, s1, s2);
	s1 = p->a1;
	s2 = p->b1;
	if (s2 == NULL && !is_sorted(s1))
	{
		split_first_stack(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	if (is_sorted(s1) && s2 != NULL)
	{
		split_second_stack(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	p->a1 = s1;
	p->b1 = s2;
}

int		call_functions(t_param *p, t_stack *s1, t_stack *s2)
{
	int a;

	a = 0;
	if (verify(s1) == 0)
	{
		median_stack(p, s1);
		while (!is_sorted(s1))
		{
			if (a == 0)
			{
				split_stack(p, s1, s2);
				s1 = p->a1;
				s2 = p->b1;
				a = 1;
			}
			conditions_functions(p, s1, s2);
			s1 = p->a1;
			s2 = p->b1;
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_param		p;
	t_stack		*s1;
	t_stack		*s2;
	int			i;

	s1 = NULL;
	s2 = NULL;
	i = 1;
	init(&p);
	if (ac == 1)
		return (0);
	while (i < ac)
	{
		if (!param_to_link(&s1, av[i]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	if (duplicated(s1) == 1)
		return (0);
	call_functions(&p, s1, s2);
	return (0);
}
