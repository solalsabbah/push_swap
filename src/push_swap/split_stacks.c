/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:23:12 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/30 15:31:54 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		bryan(t_param *p, t_stack *s1, t_stack *s2)
{
	int size;

	if ((size = lst_size(s2)) <= 30)
	{
		while (s2)
		{
			extremum_lst(s2, p);
			if (direction(s2, p, size) == 1)
			{
				while (s2->val != p->min && s2->val != p->max)
				{
					s2 = inv_rotate(s2); 
					printf("[RRA]\n");
				}
			}
			else if (direction(s2, p, size) == 2)
			{
				while (s2->val != p->min && s2->val != p->max)
				{
					s2 = rotate_list(s2); 
					printf("[RA]\n");
				}
			}
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1 = p->b1;
			printf("[PA]\n");
			if (s1->val == p->min)
			{	
				s1 = rotate_list(s1);
				printf("[RA]\n");
			}
		}
		while (s1->med < p->med)
		{
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}	
	}
		p->a1 = s1;
		p->b1 = s2;
}


void		split_second_stack(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = median_stack(p, s2);
	while (above_median(med, s2) == 1 && !is_sorted(s2))
	{
		if (s2->val ==  min_value(s2))
		{	
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1 = p->b1;
			s1->med = med;
			printf("pa\n");
			s1->med = s1->val;
			s1 = rotate_list(s1);
			printf("pa\n");
		}
		if (s2 && s2->val > med)
		{
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1 = p->b1;
			s1->med = med;
			printf("pa\n");
	//		if (s1 && s1->next  && s1->val > s1->next->val)
	//		{
	//			swap(s1);
	//			printf("[SA]\n");
	//		}
		}
		else
		{
			s2 = rotate_list(s2);
			printf("[RB]\n");
		}
	}
	p->a1 = s1;
	p->b1 = s2;
	if (lst_size(s2) > 30 && !is_sorted(s2))
		split_second_stack(p, s1, s2);
}

void		split_first_stack(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = s1->med;
	while ((s1->med == med) && !is_sorted(s1)) // here condition is wrong
	{
		if (s1->val == min_cluster(s1, s2, med))
		{
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}
		else
		{
			push(s1, s2, p);  // PB
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
			s2->med = med;
			if (s2 && s2->next && s2->val < s2->next->val)
			{
				swap(s2);
				printf("[SB]\n");
			}
		}
	}
		 p->a1 = s1;
		 p->b1 = s2;
}

void		split_stack(t_param *p, t_stack *s1, t_stack *s2) // (1)
{
	int med;

	med = median_stack(p, s1);
	p->min_med = med;
	while (below_median(med, s1) && !is_sorted(s1)) // adding is sorted  
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
	init_med(s1, s2, med);
	print_stack(s1, s2); // print stack
	s1 = p->a1;
	s2 = p->b1;
}
