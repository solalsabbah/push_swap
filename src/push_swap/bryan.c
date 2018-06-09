/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bryan.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:56:10 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/04 19:29:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		bryan_direction(t_param *p, t_stack *s1, t_stack *s2)
{
	extremum_lst(s2, p);
	if (direction(s2, p) == 1)
	{
		while (s2->val != p->min && s2->val != p->max)
		{
			s2 = inv_rotate(s2);
			ft_putstr("rrb\n");
		}
	}
	else if (direction(s2, p) == 2)
	{
		while (s2->val != p->min && s2->val != p->max)
		{
			s2 = rotate_list(s2);
			ft_putstr("rb\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
}

void		bryan(t_param *p, t_stack *s1, t_stack *s2)
{
	if ((lst_size(s2)) <= 30)
	{
		while (s2)
		{
			bryan_direction(p, s1, s2);
			s1 = p->a1;
			s2 = p->b1;
			push(s2, s1, p);
			s2 = p->a1;
			s1 = p->b1;
			ft_putstr("pa\n");
			if (s1->val == p->min)
			{
				s1 = rotate_list(s1);
				ft_putstr("ra\n");
			}
		}
		while (s1->med < p->med)
		{
			s1 = rotate_list(s1);
			ft_putstr("ra\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
}
