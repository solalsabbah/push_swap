/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:10:47 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/15 14:12:23 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_sorted(t_stack *s1)
{
	while (s1 && s1->next)
	{
		if (s1->val > s1->next->val)
			return (0);
		s1 = s1->next;
	}
	return (1);
}

int	last_val(t_stack *s1)
{
	while (s1->next)
		s1 = s1->next;
	return (s1->val);
}

int	min_value(t_stack *s1, t_param *p)
{
	int min;
	int pos;

	min = s1->val;
	pos = 0;
	while (s1 && s1->next)
	{
		if (min > s1->next->val)
		{
			min = s1->next->val;
			p->sens = pos;
		}
		s1 = s1->next;
		pos++;
	}
	if (p->sens > pos / 2)
		p->sens = 1;
	else
		p->sens = 0;
	return (min);
}

int	max_value(t_stack *s1, t_param *p)
{
	int max;

	max = s1->val;
	p->sens = p->sens;
	while (s1 && s1->next)
	{
		if (max < s1->next->val)
			max = s1->next->val;
		s1 = s1->next;
	}
	return (max);
}

int			nb_elem(t_stack *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s)
	{
		i++;
		s = s->next;
	}
	return (i);
}

int	mean_value(t_stack *s1, t_param *p)
{
	int sum;
	int c;

	sum = 0;
	c = 0;
	p->sens = p->sens;
	while (s1)
	{
		sum = sum + s1->val;
		c++;
		s1 = s1->next;
	}
	return (sum / c);
}
