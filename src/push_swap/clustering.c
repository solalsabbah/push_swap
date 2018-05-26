/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clustering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:26:58 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/26 20:33:03 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void 		sort_high_clusters(t_param *p, t_stack *s1, t_stack *s2)
{
	while (s2->med > p->min_med)
	{
		if (s2->val > s2->next->val)
		{
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1 = p->b1;
			printf("[PA]\n");
		}
		else
		{
			swap(s2);
			printf("[SB]\n");
		}
		while (s1->val > s1->next->val)
		{
			swap(s1);
			printf("[SA]\n");
			push(s1, s2, p);  // PB
			s1 = p->a1;
			s2  = p->b1;
			printf("[PB]\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
}
void 		sort_clusters(t_param *p, t_stack *s1, t_stack *s2)
{
	while (s1->med <= p->max_med)
	{
		if (s1->val < s1->next->val)
		{
			push(s1, s2, p);  // PB
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
		}
		else
		{
			swap(s1);
			printf("[SA]\n");
		}
		while (s2->val < s2->next->val)
		{
			swap(s2);
			printf("[SB]\n");
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1  = p->b1;
			printf("[PA]\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
}

/*void		sort_biggest_cluster(t_param *p, t_stack *s1, t_stack *s2)
{
	split_first_stack(p, s1, s2);
	s1 = p->a1;
	s2 = p->b1;
	sort_high_clusters(p, s1, s2);
}*/
