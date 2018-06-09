/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:38:55 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 17:39:11 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		new_fonction(t_stack **s1, t_stack **s2, char *line)
{
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "ss") == 0)
		swap_new(s1);
	else if (ft_strcmp(line, "sb") == 0 || ft_strcmp(line, "ss") == 0)
		swap_new(s2);
	else if (ft_strcmp(line, "pa") == 0)
		push_new(s2, s1);
	else if (ft_strcmp(line, "pb") == 0)
		push_new(s1, s2);
	else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rr") == 0)
		rotate_new(s1);
	else if (ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0)
		rotate_new(s2);
	else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrr") == 0)
		inv_rotate_new(s1);
	else if (ft_strcmp(line, "rrb") == 0 || ft_strcmp(line, "rrr") == 0)
		inv_rotate_new(s2);
	else
		return (0);
	return (1);
}

int		checker(t_stack **s1)
{
	int			fd;
	char		*line;
	t_stack		*s2;

	fd = 0;
	s2 = NULL;
	while (get_next_line(fd, &line))
	{
		if (!new_fonction(s1, &s2, line))
		{
			printf("error\n");
			free(line);
			return (0);
		}
		free(line);
	}
	is_sort(s1, &s2);
	return (0);
}

int		main(int ac, char **av)
{
	int			i;
	t_stack		*s1;

	if (ac == 1)
		return (0);
	i = 1;
	s1 = NULL;
	while (i < ac)
	{
		if (!param_to_link(&s1, av[i]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
	}
	if (duplicated(s1) == 1)
		return (0);
	checker(&s1);
}
