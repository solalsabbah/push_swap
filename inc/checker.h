/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:53:30 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/26 20:17:59 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9 
# define RRB 10
# define RRR 11

typedef struct	s_param
{	
	int			nb; // count of element in stack 
	int			i;  // used for table of operands
	int			min;
	int			max;
	int			med;
	int			min_med;
	int			max_med;
	int			sens;
	int			*tab;
	void		*a1;
	void		*b1;
}				t_param;

typedef struct s_stack t_stack;

struct s_stack
{
	int			val;
	int			med;
	t_stack		*next;
};


int			checker(t_stack *s1);
int			apply_op(t_param *p, t_stack *s1, t_stack *s2);
int			validate_content(char *line, t_param *p);
int			add_op(int op, t_param *p);
int			median_stack(t_param *p, t_stack *s1);
int			last_val(t_stack *s1);
int			is_sorted(t_stack *s1);
int			min_value(t_stack *s1);
int			max_value(t_stack *s1);
int			mean_value(t_stack *s1, t_param *p);
int			duplicated(t_stack *s1);
int			lst_size(t_stack *s);
int			*bubble_sort(int n, int *tab);

void		extremum_lst(t_stack *s, t_param *p);
void		bryan(t_param *p, t_stack *s1, t_stack *s2);

void			sort_two(t_stack *s1);
void			sort_three(t_stack *s1);

t_stack		*add_link(t_stack *s1, int val);
t_stack		*inv_rotate(t_stack *s1);
t_stack		*rotate_list(t_stack *s1);

void		sort_clusters(t_param *p, t_stack *s1, t_stack *s2);
void		sort_high_clusters(t_param *p, t_stack *s1, t_stack *s2);
void		sort_biggest_cluster(t_param *p, t_stack *s1, t_stack *s2);
void		split_stack(t_param *p, t_stack *s1, t_stack *s2);
void		split_second_stack(t_param *p, t_stack *s1, t_stack *s2);
void		split_first_stack(t_param *p, t_stack *s1, t_stack *s2);
void		push(t_stack *s1, t_stack *s2, t_param *p);
void		swap(t_stack *s1);
void		print_elem(t_stack *s1);
void		print_stack(t_stack *s1, t_stack *s2);
void		init(t_param *p);

void		init_med(t_stack *s1, t_stack *s2, int med);
int			below_median(int med, t_stack *s);
int			above_median(int med, t_stack *s);

#endif
