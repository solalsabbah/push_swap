/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:38:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/27 16:33:48 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			duplicated(t_stack *s1)
{
	int 	tmp;
	void	*adr;
	
	while (s1)
	{
		tmp = s1->val;
		adr = s1->next;
		s1 = s1->next;	
		while (s1)
		{
			if (tmp == s1->val)
			{
				printf("doublon\n");
				return (1);
			}
			s1 = s1->next;	
		}
		s1 = adr;	
	}
	return (0);
}

int	checker(t_param *p, t_stack *s1)
{
	int		fd;
	char		*line;
	t_stack		*s2;

	fd = 0;
	s2 = malloc(sizeof(t_stack));
	s2 = NULL; // it segfault without it !
	while (get_next_line(fd, &line) != -1)
	{
		if (ft_strcmp(line, "") == 0)
			break;
		if (validate_content(line, p) == 0)
			printf("Wrong operand\n");
		free(line);
	}
	apply_op(p, s1, s2);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack		*s1;
	t_param		p;


	if (ac == 1)
		return (0);
	i = 1;
	s1 = NULL;
	init(&p);
	while (--ac > 0)
	{
		if (ft_isnumber(av[ac]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		if (is_int(av[ac]) == 0)
		{
			printf("Error\n");
			return (0);
		}
		s1 = add_link(s1, ft_atoi(av[ac]));
	}
	print_stack(s1, NULL);
	if (duplicated(s1) == 1)
		return (0);
	checker(&p, s1);
}
