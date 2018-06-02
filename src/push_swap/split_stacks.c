/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:23:12 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 16:03:41 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		split_stack(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = median_stack(p, s1);
	p->min_med = med;
	while (below_median(med, s1))
	{
		if (s1 && s1->val <= med)
		{
			push(s1, s2, p);
			s1 = p->a1;
			s2 = p->b1;
			ft_putstr("pb\n");
		}
		else
		{
			s1 = rotate_list(s1);
			ft_putstr("ra\n");
		}
	}
	init_med(s1, s2, med);
}
