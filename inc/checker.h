/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 11:53:30 by ssabbah           #+#    #+#             */
/*   Updated: 2018/03/22 14:45:40 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H


# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define sa 1
# define sb 2
# define ss 3
# define pa 4
# define pb 5
# define ra 6
# define rb 7
# define rr 8
# define rra 9 
# define rrb 10
# define rrr 11

typedef struct	s_param
{
	
	int			*tab;
	int			nb;
	int			i; 
}				t_param;

int		checker(int *a, int elem, t_param *p);
int		apply_op(t_param *p, int *a, int *b);

#endif
