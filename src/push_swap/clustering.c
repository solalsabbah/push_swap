/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clustering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:26:58 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/12 13:21:36 by ssabbah          ###   ########.fr       */
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
