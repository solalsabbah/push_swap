/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:22:42 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 13:58:30 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_new(t_stack **lst)
{
	int tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->val;
		(*lst)->val = (*lst)->next->val;
		(*lst)->next->val = tmp;
	}
}

void	push_new(t_stack **src, t_stack **dest)
{
	t_stack *tmp;

	if (*src)
	{
		tmp = (*src)->next;
		(*src)->next = *dest;
		*dest = *src;
		*src = tmp;
	}
}

void	rotate_new(t_stack **s1)
{
	t_stack *tmp;
	t_stack *head;

	if ((*s1) && (*s1)->next)
	{
		head = *s1;
		tmp = (*s1)->next;
		while ((*s1)->next != NULL)
			*s1 = (*s1)->next;
		if ((*s1)->next == NULL)
		{
			(*s1)->next = head;
			head->next = NULL;
		}
		*s1 = tmp;
	}
}

void	inv_rotate_new(t_stack **s1)
{
	t_stack *new_head;
	t_stack *head;

	new_head = NULL;
	if ((*s1) && (*s1)->next)
	{
		head = *s1;
		while ((*s1)->next->next != NULL)
			*s1 = (*s1)->next;
		if ((*s1)->next->next == NULL)
		{
			new_head = (*s1)->next;
			(*s1)->next = NULL;
		}
		new_head->next = head;
		*s1 = new_head;
	}
}
