/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_to_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 16:04:05 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/09 17:40:00 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_tab(char **tab)
{
	int a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		tab[a] = NULL;
		a++;
	}
	free(tab[a]);
	tab[a] = NULL;
	free(tab);
}

int		param_to_link(t_stack **s1, char *str)
{
	char	**tab;
	int		a;

	tab = ft_split(str);
	a = 0;
	while (tab[a])
	{
		if (ft_isnumber(tab[a]) == 0 || is_int(tab[a]) == 0)
		{
			free_tab(tab);
			return (0);
		}
		else
			add_end(s1, ft_atoi(tab[a]));
		a++;
	}
	free_tab(tab);
	return (1);
}
