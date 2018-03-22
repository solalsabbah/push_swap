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


int	validate_content(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		add_op(sa);	
	if (ft_strcmp(line, "sb") == 0)
		add_op(sb);	
	if (ft_strcmp(line, "ss") == 0)
		add_op(ss);	
	if (ft_strcmp(line, "pa") == 0)
		add_op(pa);	
	if (ft_strcmp(line, "pb") == 0)
		add_op(pb);	
	if (ft_strcmp(line, "ra") == 0)
		add_op(ra);	
	if (ft_strcmp(line, "rb") == 0)
		add_op(rb);	
	if (ft_strcmp(line, "rr") == 0)
		add_op(rr);	
	if (ft_strcmp(line, "rra") == 0)
		add_op(rra);	
	if (ft_strcmp(line, "rrb") == 0)
		add_op(rrb);	
	if (ft_strcmp(line, "rrr") == 0)
		add_op(rrr);	
	return (0);	
}

int	checker(int *a, int elem)
{
	int fd;
	int *b;
	char *line;
		
	free(a);
	fd = 0;
	b = malloc(sizeof(int) * elem);
	printf("%d\n", sa);
	while (get_next_line(fd, &line) != -1)
	{
		printf("%s\n", line);
//		validate_content(line);
		if(ft_strcmp(line, "") == 0)
			break;
		free(line);
	}
	printf("solved\n");
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
