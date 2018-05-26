/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:19:37 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/26 17:54:00 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		init_med(t_stack *s1, t_stack *s2, int med)
{
	while (s1)
	{
		s1->med = med;
		s1 = s1->next;
	}
	while (s2)
	{
		s2->med = med - 1;
		s2 = s2->next;
	}
}

int			below_median(int med, t_stack *s)
{
	while (s)
	{
		if (s->val <= med)
			return (1);
		s = s->next;
	}
	return (0);
}

int			above_median(int med, t_stack *s)
{
	while (s)
	{
		if (s->val > med)
			return (1);
		s = s->next;
	}
	return (0);
}

int			median_stack(t_param *p, t_stack *s1)
{
	int	n;
	int	c;
	int 	*tab;
	void	*adr;

	adr = s1; 
	n = lst_size(s1);
	c = 0;
	tab = malloc(sizeof(int) * (n + 1));
	while (s1)
	{	
		tab[c] = s1->val;
		s1 = s1->next;
		c++;
	}
	bubble_sort(n, tab); // modifying directly in the adress 
	p->nb = (n + 1) / 2; 		// sorting my tab trough point
	p->med = tab[p->nb - 1];
	return (tab[p->nb - 1]);		// returnin the median value
}
