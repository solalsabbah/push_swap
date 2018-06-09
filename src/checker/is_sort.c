/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:51:39 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 17:39:30 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_del_lst(t_stack *lst)
{
	t_stack *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int		is_sort(t_stack **s1, t_stack **s2)
{
	int p;

	p = 0;
	while (*s1)
	{
		if ((*s1)->next && (*s1)->val > (*s1)->next->val)
		{
			p = 1;
			break ;
		}
		*s1 = (*s1)->next;
	}
	if (!(*s2) && p == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_del_lst(*s2);
	return (0);
}
