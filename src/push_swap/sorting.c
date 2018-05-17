/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:34:57 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/17 14:01:02 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void 		sort_clusters(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = s1->med;
	while (s1 && !is_sorted(s1))
	{
		if (s1->val < s1->next->val)
		{
			push(s1, s2, p);  // PB
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
		}
		else
		{
			swap(s1);
			printf("[SA]\n");
		}
		while (s2->val < s2->next->val)
		{
			swap(s2);
			printf("[SB]\n");
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1  = p->b1;
			printf("[PA]\n");
		}
	}
}

void		split_second_stack(t_param *p, t_stack *s1, t_stack *s2)
{	
	int med;

	med = median_stack(p, s2);
	while (above_median(med, s2) == 1)
	{
		if (s2 && s2->val > med)
		{
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1  = p->b1;
			s1->med = med;
			printf("[PA]\n");
			if (s1 && s1->next  && s1->val > s1->next->val)
			{
				swap(s1);
				printf("[SA]\n");
			}
		}
		else 
		{
			s2 = rotate_list(s2);
			printf("[RB]\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
	if (nb_elem(s2) > 1) 
		split_second_stack(p, s1, s2);
	else
	{ 
		s2->med = med - 1;
		sort_clusters(p, s1, s2);
	}
}

void		split_first_stack(t_param *p, t_stack *s1, t_stack *s2)
{	
	int med;

	med = median_stack(p, s1);
	while (above_median(med, s2) == 1)
	{
		if (s2 && s2->val > med)
		{
			push(s1, s2, p);  // PB
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
			s2->med = med;
			if (s2 && s2->next  && s2->val > s2->next->val)
			{
				swap(s2);
				printf("[SB]\n");
			}
		}
		else 
		{
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
	if (nb_elem(s2) > 1) 
		split_second_stack(p, s1, s2);
	else
	{ 
		s2->med = med - 1;
		printf("FINIShED \n\n\n\n");
		//sort_clusters(p, s1, s2);
	}
}


void		sort_biggest_cluster(t_param *p, t_stack *s1, t_stack *s2)
{
	printf("je suis la\n\n");
	//segfai;t
	split_first_stack(p, s1, s2);
	s1 = p->a1;
	s2 = p->b1;
	print_stack(s1, s2);
}

void		split_stack(t_param *p, t_stack *s1, t_stack *s2) // one way to sort the stack using only RA && RRA && PB && PA
{
	int med;
	int min;

	med = median_stack(p, s1);
	if (nb_elem(s1) > 1)
	{
		while (below_median(med, s1))
		{
			if (s1 && s1->val <= med)
			{
				push(s1, s2, p);  // PB
				s1 = p->a1;
				s2 = p->b1;
				printf("[PB]\n");
			}
			else 
			{
				s1 = rotate_list(s1);
				printf("[RA]\n");
			}
		}
	}
	init_med(s1, med);
	min = min_value(s1, p);
	sort_biggest_cluster(p, s1, s2); //can biggest sort cluster now
	printf("EXIT\n");
	exit (0);
	if (s2) 
	{
		split_second_stack(p, s1, s2);
	}
		s1 = p->a1;
		s2 = p->b1;
	print_stack(s1, s2);
}
