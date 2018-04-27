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
	int 	*tab;
	void	*adr;

	adr = s1; 
	n = 0;
	while (s1 || adr)
	{
		if (!adr)
			tab[n] = s1->val;
		n++;
		s1 = s1->next;
		if (s1 == NULL && adr != NULL) 
		{
			s1 = adr;
			adr = NULL;
			tab = malloc(sizeof(int) * n);
			n = 0;
		}
	}	
	bubble_sort(n, tab);
	p->nb = (n + 1) / 2; 		// sorting my tab trough point
	p->med = tab[p->nb];
	return (tab[p->nb]);		// returnin the median value
}
