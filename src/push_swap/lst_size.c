#include "checker.h"

int	lst_size(t_stack *s)
{
	int i;

	i = 0;
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}
