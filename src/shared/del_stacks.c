/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:20:50 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 14:02:46 by ssabbah          ###   ########.fr       */
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
