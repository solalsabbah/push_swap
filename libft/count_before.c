/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_before.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:17:28 by ssabbah           #+#    #+#             */
/*   Updated: 2017/04/27 14:18:31 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		count_before(char const *s)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		count++;
		i++;
	}
	return (count);
}
