/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:24:29 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/09 21:14:33 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack *add_front(t_stack *s1, t_stack *s2)
{
	s1->next = s2;
	return (s2);
}

t_stack	*add_link(t_stack *s1, int val)
{
	t_stack *tmp;

	tmp = malloc(sizeof(t_stack));
	if (tmp)
	{
		tmp->val = val;
		tmp->next = s1;
	}
	return (tmp);
}

t_stack *inv_rotate(t_stack *s1)
{
	t_stack *tmp;
	t_stack *bis;

	tmp = s1;
	while (s1 != NULL)
	{
		if (s1->next && !s1->next->next)
		{
			bis = s1->next;
			s1->next = NULL;
			bis->next = tmp;
			return (bis);
		}
		s1 = s1->next;
	}
	return (NULL);

}

t_stack *rotate_list(t_stack *s1)
{

	/// how to free the first stack  ? //
	t_stack *tmp;
	t_stack *adr;

	adr = s1->next;
	tmp = s1;	
	while (s1 != NULL)
	{
		if (s1->next == NULL)
		{
			s1->next = tmp;
			tmp->next = NULL;
			return (adr);
		}
		s1 = s1->next;
	}
	return (NULL);
}

void	print_elem(t_stack *s1)
{
	printf("elem %d\n", s1->val);
}
