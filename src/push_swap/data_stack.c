#include "checker.h"

int	is_sorted(t_stack *s1)
{
	while (s1 && s1->next)
	{
		if (s1->val > s1->next->val)
			return (0);
		s1 = s1->next;
	}
	return (1);
}

int	min_value(t_stack *s1, t_param *p)
{
	int min;
	int pos;
		
	min = s1->val;
	pos = 0;
	while (s1 && s1->next)
	{
		if (min > s1->next->val)
		{
			min = s1->next->val;
			p->sens = pos;
		}
		s1 = s1->next;
		pos++;
	}
	if (p->sens > pos / 2)
		p->sens = 1;
	else
		p->sens = 0;
	return (min);
}
