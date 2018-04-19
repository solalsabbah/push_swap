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

int	min_value(t_stack *s1)
{
	int min; 
		
	min = s1->val;
	while (s1 && s1->next)
	{
		if (min > s1->next->val)
			min = s1->next->val;
		s1 = s1->next;
	}
	return (min);
}
