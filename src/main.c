/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:38:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/03/22 14:45:27 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


int	add_op(int op, t_param *p)
{
	printf("[%d]\n", op);
	p->tab[p->i] = op;
	p->i++;
	return (1);
}

int	validate_content(char *line, t_param *p)
{
	int n;

	n = 0;
	if (ft_strcmp(line, "sa") == 0)
		n = add_op(sa, p);	
	if (ft_strcmp(line, "sb") == 0)
		n = add_op(sb, p);	
	if (ft_strcmp(line, "ss") == 0)
		n = add_op(ss, p);	
	if (ft_strcmp(line, "pa") == 0)
		n = add_op(pa, p);	
	if (ft_strcmp(line, "pb") == 0)
		n = add_op(pb, p);	
	if (ft_strcmp(line, "ra") == 0)
		n = add_op(ra, p);	
	if (ft_strcmp(line, "rb") == 0)
		n = add_op(rb, p);	
	if (ft_strcmp(line, "rr") == 0)
		n = add_op(rr, p);	
	if (ft_strcmp(line, "rra") == 0)
		n = add_op(rra, p);	
	if (ft_strcmp(line, "rrb") == 0)
		n = add_op(rrb, p);	
	if (ft_strcmp(line, "rrr") == 0)
		n = add_op(rrr, p);
	return (n);
}

int	checker(int *a, int elem, t_param *p)
{
	int		fd;
	int		*b;
	char		*line;
		
	free(a);
	fd = 0;
	b = malloc(sizeof(int) * elem);
	while (get_next_line(fd, &line) != -1)
	{
		if (ft_strcmp(line, "") == 0)
			break;
		if (validate_content(line, p) == 0)
			printf("Wrong operand\n");
		free(line);
	}
	apply_op(p, a , b);
	return (0);
}

void	init(t_param *p, int ac)
{
	p->i = 0;
	p->nb = ac;
	p->tab = malloc(sizeof(int) * 2048);
}

int	main(int ac, char **av)
{
	int		i;
	int		*a;
	t_param p;

	i = 1;
	a = malloc(sizeof(int) * ac);
	init(&p, ac);
	while (i < ac)
	{
		if (ft_isnumber(av[i]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	checker(a, ac - 1, &p);
	printf("finished\n");
}

//Entree standard : read 
