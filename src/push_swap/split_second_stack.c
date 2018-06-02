/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_second_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:56:53 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 16:04:23 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		apply_cond(int med, t_param *p, t_stack *s1, t_stack *s2)
{
	push(s2, s1, p);
	s2 = p->a1;
	s1 = p->b1;
	s1->med = med;
	ft_putstr("pa\n");
	s1->med = s1->val;
	s1 = rotate_list(s1);
	ft_putstr("ra\n");
	p->a1 = s1;
	p->b1 = s2;
}

void		second_condition(int med, t_param *p, t_stack *s1, t_stack *s2)
{
	if (s2->val == min_value(s2))
	{
		apply_cond(med, p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	if (s2 && s2->val > med)
	{
		push(s2, s1, p);
		s2 = p->a1;
		s1 = p->b1;
		s1->med = med;
		ft_putstr("pa\n");
	}
	else
	{
		s2 = rotate_list(s2);
		ft_putstr("rb\n");
	}
	p->a1 = s1;
	p->b1 = s2;
}

void		split_second_stack(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = median_stack(p, s2);
	while (above_median(med, s2) == 1 && !is_sorted(s2))
	{
		second_condition(med, p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	if (is_sorted(s1) && s2 != NULL)
	{
		push(s2, s1, p);
		s2 = p->a1;
		s1 = p->b1;
		s1->med = med;
		ft_putstr("pa\n");
	}
	p->a1 = s1;
	p->b1 = s2;
	if (lst_size(s2) > 30 && !is_sorted(s2))
		split_second_stack(p, s1, s2);
}
