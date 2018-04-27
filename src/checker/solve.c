/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:30:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/27 15:14:23 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int position(int a)
{
	a = 0;
	return (0);	
}

int is_sort(t_stack *s1, t_stack *s2)
{
	int p;

	p = 0;
	while (s1) 
	{
		if (s1->next && s1->val > s1->next->val)
		{
			p = 1;
			break;
		}
		s1 = s1->next;
	}
	if (!s2 && p == 0)
		printf("OK\n");	
	else
		printf("KO\n");
	return (0);
}

int apply_op(t_param *p, t_stack *s1, t_stack *s2)
{
	int n;

	n = -1;
	while (n < p->i)
	{
		if ((p->tab[n] == SA || p->tab[n] == SS) && s1 && s1->next)
			swap(s1);
		if ((p->tab[n] == SB || p->tab[n] == SS) && s2 && s2->next)
			swap(s2);
		if (p->tab[n] == PB && s1)
		{
			push(s1, s2, p);
			s1 = p->a1;
			s2 = p->b1;
			p->a1 = NULL;
			p->b1 = NULL;
			
		}
		if (p->tab[n] == PA && s2)
		{
			push(s2, s1, p);
			s2 = p->a1;
			s1 = p->b1;
			p->a1 = NULL;
			p->b1 = NULL;
		}	
		if ((p->tab[n] == RA || p->tab[n] == RR) && s1)
			s1 = rotate_list(s1);
		if ((p->tab[n] == RB || p->tab[n] == RR) && s2) 
			s2 = rotate_list(s2);
		if ((p->tab[n] == RRA || p->tab[n] == RRR) && s1) 
			s1 = inv_rotate(s1);
		if ((p->tab[n] == RRB || p->tab[n] == RRR) && s2) 
			s2 = inv_rotate(s2);
		n++;
	}
//	print_stack(s1, s2);	
	is_sort(s1, s2);
	return (0);
}
