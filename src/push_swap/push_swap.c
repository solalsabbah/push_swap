/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:55:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/11 16:26:28 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack		*s1;

	if (ac == 1)
		return (0);
	i = 1;
	s1 = NULL;
	while (--ac > 0)
	{
		if (ft_isnumber(av[ac]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		s1 = add_link(s1, ft_atoi(av[ac]));
	}
	print_stack(s1, NULL);
	return (0);
}
