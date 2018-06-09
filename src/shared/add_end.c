/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:30:53 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 17:30:27 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_end(t_stack **s1, int val)
{
	t_stack *tmp;

	tmp = *s1;
	if (*s1 == NULL)
	{
		(*s1) = malloc(sizeof(t_stack));
		(*s1)->val = val;
		(*s1)->next = NULL;
		tmp = *s1;
	}
	else
	{
		while ((*s1)->next != NULL)
			*s1 = (*s1)->next;
		(*s1)->next = malloc(sizeof(t_stack));
		(*s1)->next->val = val;
		(*s1)->next->next = NULL;
	}
	*s1 = tmp;
}
