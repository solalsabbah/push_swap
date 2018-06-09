/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:03:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 14:05:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
