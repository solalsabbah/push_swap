/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clustering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:26:58 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 16:03:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		min_cluster(t_stack *s, t_stack *s2, int med)
{
	int min;

	min = s->val;
	while (s && s->med == med)
	{
		if (s->val < min)
			min = s->val;
		s = s->next;
	}
	while (s2 && s2->med == med)
	{
		if (s2->val < min)
			min = s2->val;
		s2 = s2->next;
	}
	return (min);
}

void	sort_clusters_bis(t_param *p, t_stack *s1, t_stack *s2)
{
	while (s2->val < s2->next->val)
	{
		swap(s2);
		ft_putstr("[SB]\n");
		push(s2, s1, p);
		s2 = p->a1;
		s1 = p->b1;
		ft_putstr("[PA]\n");
	}
	p->a1 = s1;
	p->b1 = s2;
}

void	sort_clusters(t_param *p, t_stack *s1, t_stack *s2)
{
	while (s1->med <= p->max_med)
	{
		if (s1->val < s1->next->val)
		{
			push(s1, s2, p);
			s1 = p->a1;
			s2 = p->b1;
			ft_putstr("[PB]\n");
		}
		else
		{
			swap(s1);
			ft_putstr("[SA]\n");
		}
		sort_clusters_bis(p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
	}
	p->a1 = s1;
	p->b1 = s2;
}
