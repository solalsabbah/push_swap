#include "checker.h"

int	last_val(t_stack *s1)
{
	while (s1->next)
		s1 = s1->next;
	return (s1->val);
}

void		split_stack(t_param *p, t_stack *s1, t_stack *s2) // one way to sort the stack using only RA && RRA && PB && PA
{
	int min;

	while (s1->next && last_val(s1) <= s1->next->val)
	{
		if (!s2)
		{	
			push(s1, s2, p);  // push
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
		}
		//	if (s1->next && s1->next->val == min)
		//	{
//		swap(s1);
//		printf("[SA]\n");
		//	}
		//	else if (p->sens == 0 && s1->val != min)
		//	{
		s1 = rotate_list(s1);
		printf("[RA]\n");
		//	}

		// ca segfault pour 2 parametres
	}
	min = min_value(s1, p);
	while (s1->val != min || !is_sorted(s1))
	{
		if (s1->next && s1->next->val == min)
		{
			swap(s1);
			printf("[SA]\n");
		}
		else if (p->sens == 0 && s1->val != min)
		{
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}
		else
		{
			s1 = inv_rotate(s1);
			printf("[RRA]\n");
		}
		if (s1->val == min && !is_sorted(s1))
		{
			push(s1, s2, p);  // push
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
			min = min_value(s1, p);
		}
	}
	while (s2)
	{
		push(s2, s1, p);  // push
		s2 = p->a1;
		s1 = p->b1;
		printf("[PA]\n");
	}
	print_stack(s1, s2);
}
