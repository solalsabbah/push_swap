/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:56:27 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 13:56:30 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	lst_size(t_stack *s)
{
	int i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}
