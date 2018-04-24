/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:28:43 by ssabbah           #+#    #+#             */
/*   Updated: 2018/04/24 14:33:37 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack *s1)
{
	int tmp;

	tmp = s1->val;
	s1->val = s1->next->val;
	s1->next->val = tmp;
}

void	push(t_stack *s1, t_stack *s2, t_param *p) // push s1 on s2
{
	p->b1 = add_link(s2, s1->val);
	p->a1 = s1->next;
//	free(s1); // qd je free ca fait boucle infi
//	free(s2);	
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

	if (s1->next) 
		adr = s1->next;
	else 
		adr = NULL;
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
