/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:23:12 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/26 21:59:12 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			direction(t_stack *s, t_param *p, int size)
{
	int i;

	i = 0;
	while(s->val && s->val != p->min && s->val != p->max)
	{
		i++;
		s = s->next;
	}
	if (i == 0)
		return (0);
	if (i > size / 2)
		return (1);
	else
		return (2);
}

void		set_med(t_stack *s, int med)
{
		while (s)
		{
			s->med = med;
			s = s->next;
		}
}

int		min_cluster(t_stack *s, t_stack *s2, int med)
{
	int min;

	min = s->val;
	while (s && s->med == med)
	{
		if (s->val < min)
			min = s->val;
		s = s->next;
	}
	while (s2 && s2->med == med)
	{
		if (s2->val < min)
			min = s2->val;
		s2 = s2->next;
	}
	return (min);
}


void		bryan(t_param *p, t_stack *s1, t_stack *s2)
{
	int size;

	if ((size = lst_size(s2)) < 30)
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
			printf("[PA]\n");
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}
		if (s2 && s2->val > med)
		{
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1 = p->b1;
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
	if (lst_size(s2) > 30 && !is_sorted(s2))
		split_second_stack(p, s1, s2);
	else
		set_med(s2, med - 1);
}

void		bryan_bis(t_param *p, t_stack *s1, t_stack *s2)
{
	int size;

	if ((size = lst_size(s2)) < 30)
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

void		split_second_stack_bis(t_param *p, t_stack *s1, t_stack *s2)
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
			printf("[PA]\n");
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}
		if (s2 && s2->val > med)
		{
			push(s2, s1, p);  // PA
			s2 = p->a1;
			s1 = p->b1;
			s1->med = med;
			printf("[PA]\n");
		}
		else
		{
			s2 = rotate_list(s2);
			printf("[RB]\n");
		}
	}
//	print_stack(s1, s2);
	bryan_bis(p, s1, s2);
	p->a1 = s1;
	p->b1 = s2;
//	print_stack(s1, s2);
//	if (lst_size(s2) > 30 && !is_sorted(s2))
//		split_second_stack(p, s1, s2);
//	else
//		set_med(s2, med - 1);
}

void		split_first_stack(t_param *p, t_stack *s1, t_stack *s2)
{
	int med;

	med = s1->med;
	while ((s1->med <= med) && !is_sorted(s1))
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
 	bryan(p, s1, s2);
	s1 = p->a1;
	s2 = p->b1;
	if (!is_sorted(s1))
		split_first_stack(p, s1, s2);
	else
	{
		s1 = p->a1;
		s2 = p->b1;
		print_stack(s1, s2);
	// split_second_stack_bis(p, s1, s2);
	//	print_stack(p->a1, p->b1);
	}
//	s1->med = s1->val - 1;
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
