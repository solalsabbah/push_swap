/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:08:06 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 16:05:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_three(t_stack *s1)
{
	if (!is_sorted(s1))
	{
		if (s1->val < s1->next->val && s1->val < s1->next->next->val)
		{
			ft_putstr("rra\n");
			ft_putstr("sa\n");
		}
		else if (s1->val > s1->next->val && s1->next->val > s1->next->next->val)
		{
			ft_putstr("sa\n");
			ft_putstr("rra\n");
		}
		else if (s1->val > s1->next->next->val &&
				s1->next->val < s1->next->next->val)
		{
			ft_putstr("ra\n");
		}
		else if (s1->val < s1->next->next->val && s1->next->val < s1->val)
		{
			ft_putstr("sa\n");
		}
		else
			ft_putstr("rra\n");
	}
}

void	sort_two(t_stack *s1)
{
	if (!is_sorted(s1))
	{
		swap(s1);
		ft_putstr("sa\n");
	}
}
