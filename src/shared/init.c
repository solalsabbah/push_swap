#include "checker.h"

int	add_op(int op, t_param *p)
{
	p->tab[p->i] = op;
	p->i++;
	return (1);
}

int	validate_content(char *line, t_param *p)
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
	if (ft_strcmp(line, "rra") == 0)
		n = add_op(RRA, p);
	if (ft_strcmp(line, "rrb") == 0)
		n = add_op(RRB, p);
	if (ft_strcmp(line, "rrr") == 0)
		n = add_op(RRR, p);
	return (n);
}

int	checker(t_param *p, t_stack *s1)
{
	int		fd;
	char		*line;
	t_stack		*s2;

	fd = 0;
	s2 = malloc(sizeof(t_stack));
	s2 = NULL; // it segfault without it ! 
	while (get_next_line(fd, &line) != -1)
	{
		if (ft_strcmp(line, "") == 0)
			break;
		if (validate_content(line, p) == 0)
			printf("Wrong operand\n");
		free(line);
	}
	apply_op(p, s1, s2);
	return (0);
}

void	init(t_param *p)
{
	p->i = 0;
	p->nb = 0;
	p->tab = malloc(sizeof(int) * 2048); // need to make a greated size or i should use a stack ? 
	p->a1 = NULL;
	p->b1 = NULL;
}
