/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:38:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/03/21 19:38:59 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	int i;
	int *tab;

	i = 1;
	tab = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		if (ft_isnumber(av[i]) == 0)
			return (0);
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (0);
}

//Entree standard : read 
