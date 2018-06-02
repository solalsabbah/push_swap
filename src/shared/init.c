/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:45:32 by ssabbah           #+#    #+#             */
/*   Updated: 2018/06/02 13:51:20 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		add_op(int op, t_param *p)
{
	p->tab[p->i] = op;
	p->i++;
	return (1);
}

int		validate_content_bis(char *line, t_param *p)
{
	int n;

	n = 0;
	if (ft_strcmp(line, "rra") == 0)
		n = add_op(RRA, p);
	if (ft_strcmp(line, "rrb") == 0)
		n = add_op(RRB, p);
	if (ft_strcmp(line, "rrr") == 0)
		n = add_op(RRR, p);
	return (n);
}

int		validate_content(char *line, t_param *p)
{
	int n;

	n = 0;
	if (ft_strcmp(line, "sa") == 0)
		n = add_op(SA, p);
	if (ft_strcmp(line, "sb") == 0)
		n = add_op(SB, p);
	if (ft_strcmp(line, "ss") == 0)
		n = add_op(SS, p);
	if (ft_strcmp(line, "pa") == 0)
		n = add_op(PA, p);
	if (ft_strcmp(line, "pb") == 0)
		n = add_op(PB, p);
	if (ft_strcmp(line, "ra") == 0)
		n = add_op(RA, p);
	if (ft_strcmp(line, "rb") == 0)
		n = add_op(RB, p);
	if (ft_strcmp(line, "rr") == 0)
		n = add_op(RR, p);
	if (n == 0)
		n = validate_content_bis(line, p);
	return (n);
}

void	init(t_param *p)
{
	p->i = 0;
	p->nb = 0;
	p->tab = malloc(sizeof(int) * 2048);
	p->a1 = NULL;
	p->b1 = NULL;
	p->sens = 0;
}
