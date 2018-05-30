#include "checker.h"

void    sort_three(t_stack *s1)
{
	if(!is_sorted(s1))
	{
		if (s1->val < s1->next->val && s1->val < s1->next->next->val)
		{
			printf("rra\n");
			printf("sa\n");
		}
		else if (s1->val > s1->next->val && s1->next->val > s1->next->next->val)
		{
			printf("sa\n");
			printf("rra\n");
		}
		else if (s1->val > s1->next->next->val && s1->next->val < s1->next->next->val)
		{
			printf("ra\n");
		}
		else if (s1->val < s1->next->next->val && s1->next->val < s1->val)
		{
			printf("sa\n");
		}
		else
			printf("rra\n");
	}
}

void    sort_two(t_stack *s1)
{
	if (!is_sorted(s1))
	{
		swap(s1);
		printf("sa\n");
	}
}
