/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:24:29 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/01 14:12:37 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*add_front(t_stack *s1, t_stack *s2)
{
	s1->next = s2;
	return (s2);
}

t_stack	*add_link(t_stack *s1, int val)
{
	t_stack *tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp)
	{
		tmp->val = val;
		tmp->next = s1;
	}
	return (tmp);
}

void	print_elem(t_stack *s1)
{
	printf("elem %d\n", s1->val);
}
