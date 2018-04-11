/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:30:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/11 16:24:52 by ssabbah          ###   ########.fr       */
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
	while (s1) 
	{
		if (s1->next && s1->val > s1->next->val)
			return (0);
		s1 = s1->next;
	}
	if (!s2)
		return (1);
	return (0);
}

int apply_op(t_param *p, t_stack *s1)
{
	int n;
	int tmp;
	t_stack *adr;
	t_stack *s2;

	n = 0;
	s2 = malloc(sizeof(t_stack));
	s2 = NULL;
	while (n < p->i)
	{
		if ((p->tab[n] == SA || p->tab[n] == SS) && s1 && s1->next)
		{
			tmp = s1->val;
			s1->val = s1->next->val;
			s1->next->val = tmp;
		}
		if ((p->tab[n] == SB || p->tab[n] == SS) && s2 && s2->next)
		{
			tmp = s2->val;
			s2->val = s2->next->val;
			s2->next->val = tmp;
		}
		if (p->tab[n] == PB && s1)
		{
			adr = s1;
			s2 = add_link(s2, s1->val);
			s1 = s1->next;
			free(adr);
		}
		if (p->tab[n] == PA && s2)
		{
			adr = s2;
			s1 = add_link(s1, s2->val);
			s2 = s2->next;
			free(adr);
		}	
		if ((p->tab[n] == RA || p->tab[n] == RR) && s1)
		{
			s1 = rotate_list(s1);
		}
		if ((p->tab[n] == RB || p->tab[n] == RR) && s2) 
		{
			s2 = rotate_list(s2);
		}
		if (p->tab[n] == RRA && s1) 
		{
			s1 = inv_rotate(s1);
		}
		if (p->tab[n] == RRB && s2) 
		{
			s2 = inv_rotate(s2);
		}
		if (p->tab[n] == RRR && s1 && s2) 
		{
			s1 = inv_rotate(s1);
			s2 = inv_rotate(s2);
		}
		n++;
	}
	print_stack(s1, s2);
	if (is_sort(s1, s2) == 1) 
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
