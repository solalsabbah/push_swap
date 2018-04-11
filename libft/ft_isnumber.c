/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:01:31 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/11 16:38:06 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumber(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i]) 
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
