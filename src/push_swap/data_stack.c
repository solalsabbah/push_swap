/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:10:47 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/30 15:42:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		direction(t_stack *s, t_param *p, int size)
{
	int i;

	i = 0;
	while (s->val && s->val != p->min && s->val != p->max)
	{
		i++;
		s = s->next;
	}
	if (i == 0)
		return (0);
	if (i > size / 2)
		return (1);
	else
		return (2);
}

int		is_sorted(t_stack *s1)
{
	while (s1 && s1->next)
	{
		if (s1->val > s1->next->val)
			return (0);
		s1 = s1->next;
	}
	return (1);
}
