/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:10:47 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/26 20:18:09 by ssabbah          ###   ########.fr       */
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

void extremum_lst(t_stack *s, t_param *p)
{
	int min;
	int max;

	min = s->val;
	max = s->val;
	while (s && s->next)
	{
		if (min > s->next->val)
			min = s->next->val;
		if (max < s->next->val)
			max = s->next->val;
		s = s->next;
	}
	p->min = min;
	p->max = max;
}

int	min_value(t_stack *s)
{
	int min;

	min = s->val;
	while (s && s->next)
	{
		if (min > s->next->val)
			min = s->next->val;
		s = s->next;
	}
	return (min);
}

int	max_value(t_stack *s1)
{
	int max;

	max = s1->val;
	while (s1 && s1->next)
	{
		if (max < s1->next->val)
			max = s1->next->val;
		s1 = s1->next;
	}
	return (max);
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
