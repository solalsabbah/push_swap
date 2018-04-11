/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:55:00 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/11 18:24:25 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	int		i;
	int 	med;
	t_stack		*s1;
	t_stack 	*s2;
	
	i = 1;
	s1 = NULL;
	s2 = malloc(sizeof(t_stack));
	if (ac == 1)
		return (0);
	while (--ac > 0)
	{
		if (ft_isnumber(av[ac]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		s1 = add_link(s1, ft_atoi(av[ac]));
	}
	med = median_stack(s1);
//	split_stack(med, s1, s2);
	printf("med %d\n", med);
	print_stack(s1, NULL);
	return (0);
}
