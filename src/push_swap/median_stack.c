/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:19:37 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/11 18:53:59 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


void		split_stack(int med, t_stack *s1, t_stack *s2)
{

		/// parcourir les n premiers elements et sassurer quils sont sous la mediane
		/// besoin de recuperer le n 
		/// separer en 2 stacks 
}	

int			median_stack(t_stack *s1)
{
	int		n;
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
	bubble_sort(n, tab); 			// sorting my tab trough point
	return (tab[(n + 1)  / 2]);		// returnin the median value
}
