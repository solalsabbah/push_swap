/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:50:07 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/11 18:00:43 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			*bubble_sort(int n, int *tab)
{
	int c;
	int tmp;

	c = 0;
	tmp = 0;
	while (c != n - 1)
	{
		while (c < n - 1)
		{
			if (tab[c] > tab[c + 1])
			{
				tmp = tab[c];
				tab[c] = tab[c + 1];
				tab[c + 1] = tmp;
			}
			c++;
		}
		c = 0;
		n--;
	}
	return (tab);
}
