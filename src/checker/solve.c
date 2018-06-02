/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:30:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 17:06:01 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del_stacks(t_stack *s1, t_stack *s2)
{
	t_stack *tmp;

	if (s1 != NULL)
	{
		while (s1)
		{
			tmp = s1;
			s1 = s1->next;
			free(tmp);
		}
		tmp = NULL;
	}
	if (s2 != NULL)
	{
		while (s2)
		{
			tmp = s2;
			s2 = s2->next;
			free(tmp);
		}
		tmp = NULL;
	}
}

int		is_sort(t_stack *s1, t_stack *s2)
{
	int p;

	p = 0;
	while (s1)
	{
		if (s1->next && s1->val > s1->next->val)
		{
			p = 1;
			break ;
		}
		s1 = s1->next;
	}
	if (!s2 && p == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}

void	verify_condition(int op, t_param *p, t_stack *s1, t_stack *s2)
{
	if ((op == SA || op == SS) && s1 && s1->next)
		swap(s1);
	if ((op == SB || op == SS) && s2 && s2->next)
		swap(s2);
	if ((op == RA || op == RR) && s1)
		s1 = rotate_list(s1);
	if ((op == RB || op == RR) && s2)
		s2 = rotate_list(s2);
	if ((op == RRA || op == RRR) && s1)
		s1 = inv_rotate(s1);
	if ((op == RRB || op == RRR) && s2)
		s2 = inv_rotate(s2);
	if (op == PB && s1)
	{
		push(s1, s2, p);
		s1 = p->a1;
		s2 = p->b1;
	}
	p->a1 = s1;
	p->b1 = s2;
}

int		apply_op(t_param *p, t_stack *s1, t_stack *s2)
{
	int n;

	n = -1;
	while (n++ < p->i)
	{
		verify_condition(p->tab[n], p, s1, s2);
		s1 = p->a1;
		s2 = p->b1;
		if (p->tab[n] == PA && s2)
		{
			push(s2, s1, p);
			s2 = p->a1;
			s1 = p->b1;
			p->a1 = NULL;
			p->b1 = NULL;
		}
	}
	is_sort(s1, s2);
	del_stacks(s1, s2);
	return (0);
}
