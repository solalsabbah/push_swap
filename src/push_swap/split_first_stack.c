/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:57:27 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 16:04:03 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		first_condition(int med, t_param *p, t_stack *s1, t_stack *s2)
{
	if (s1->val == min_cluster(s1, s2, med))
	{
		s1 = rotate_list(s1);
		ft_putstr("ra\n");
	}
	else
	{
		push(s1, s2, p);
		s1 = p->a1;
		s2 = p->b1;
		ft_putstr("pb\n");
		s2->med = med;
		if (s2 && s2->next && s2->val < s2->next->val)
		{
			swap(s2);
			ft_putstr("sb\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
}

void		split_first_stack(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = s1->med;
	while ((s1->med == med) && !is_sorted(s1))
	{
		first_condition(med, p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	p->a1 = s1;
	p->b1 = s2;
}
