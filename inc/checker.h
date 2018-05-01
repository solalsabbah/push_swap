/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:53:30 by ssabbah           #+#    #+#             */
/*   Updated: 2018/05/01 14:04:57 by ssabbah          ###   ########.fr       */
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
	int			med;
	int			sens;
	int			*tab;
	void			*a1;
	void			*b1;
}				t_param;

typedef struct s_stack t_stack;

struct s_stack
{
	int			val;
	t_stack		*next;
};


int			checker(t_stack *s1);
int			apply_op(t_param *p, t_stack *s1, t_stack *s2);
int			validate_content(char *line, t_param *p);
int			add_op(int op, t_param *p);
int			median_stack(t_param *p, t_stack *s1);
int			last_val(t_stack *s1);
int			is_sorted(t_stack *s1);
int			min_value(t_stack *s1, t_param *p);
int			max_value(t_stack *s1, t_param *p);
int			mean_value(t_stack *s1, t_param *p);
int			nb_elem(t_stack *s);
int			duplicated(t_stack *s1);

int			*bubble_sort(int n, int *tab);

t_stack		*add_link(t_stack *s1, int val);
t_stack		*inv_rotate(t_stack *s1);
t_stack		*rotate_list(t_stack *s1);

void		split_stack(t_param *p, t_stack *s1, t_stack *s2);
void		push(t_stack *s1, t_stack *s2, t_param *p);
void		swap(t_stack *s1);
void		print_elem(t_stack *s1);
void		print_stack(t_stack *s1, t_stack *s2);
void		init(t_param *p);

#endif
