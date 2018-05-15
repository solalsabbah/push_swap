/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:00:06 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/15 13:41:57 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_stack(t_stack *s1, t_stack *s2)
{
	while (s1 || s2)
	{
		if (!s1)
			printf("       ||");
		if (s1)
		{
			printf("[%4d] %d ||", s1->val, s1->med);
			s1 = s1->next;
		}
		if (!s2)
			printf("   \n");
		if (s2)
		{
			printf(" [%4d]\n", s2->val);
			s2 = s2->next;
		}
	}
}
