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


int	validate_content(char *line);
int	checker(int *a, int elem)
{
	int fd;
	int *b;
	char *line;
		
	free(a);
	fd = 0;
	b = malloc(sizeof(int) * elem);
	while (get_next_line(fd, &line) != -1)
	{
		printf("%s\n", line);
		if(ft_strcmp(line, "") == 0)
			break;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int i;
	int *tab;

	i = 1;
	tab = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		if (ft_isnumber(av[i]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		tab[i - 1] = ft_atoi(av[i]);
		i++;
	}
	checker(tab, ac - 1);
	return (0);
}

//Entree standard : read 
