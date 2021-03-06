/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 15:01:38 by ssabbah           #+#    #+#             */
/*   Updated: 2017/10/03 15:12:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen_int(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
