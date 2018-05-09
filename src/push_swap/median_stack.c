/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:19:37 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/27 17:17:30 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			median_stack(t_param *p, t_stack *s1)
{
	int	n;
	int	c;
	int 	*tab;
	void	*adr;

	adr = s1; 
	n = nb_elem(s1);
	c = 0;
	tab = malloc(sizeof(int) * (n + 1));
	while (s1)
	{	
		tab[c] = s1->val;
		s1 = s1->next;
		c++;
	}
	bubble_sort(n, tab); // modifying directly in the adress
	// until here ok ! 
	p->nb = (n + 1) / 2; 		// sorting my tab trough point
	p->med = tab[p->nb - 1];
	return (tab[p->nb - 1]);		// returnin the median value
}
