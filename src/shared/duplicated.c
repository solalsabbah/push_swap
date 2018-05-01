/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicated.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:04:12 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/01 14:05:17 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	duplicated(t_stack *s1)
{
	int		tmp;
	void	*adr;

	while (s1)
	{
		tmp = s1->val;
		adr = s1->next;
		s1 = s1->next;
		while (s1)
		{
			if (tmp == s1->val)
			{
				printf("doublon\n");
				return (1);
			}
			s1 = s1->next;
		}
		s1 = adr;
	}
	return (0);
}
