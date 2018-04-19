#include "checker.h"

int	last_val(t_stack *s1)
{
	while (s1->next)
		s1 = s1->next;
	return (s1->val);
}

void		split_stack(t_param *p, t_stack *s1, t_stack *s2) // one way to sort the stack using only RRA && PB && PA
{
	int min;

	min = min_value(s1);
	while (s1->val != min || !is_sorted(s1))
	{
		s1 = inv_rotate(s1);
		printf("[RRA]\n");
		if (s1->val == min)
		{
			push(s1, s2, p);  // push
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
			min = min_value(s1);
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


/*
   void		split_stack(t_param *p, t_stack *s1, t_stack *s2)
   {
   while (p->nb > 0) // is sorted 
   {
   while (last_val(s1) <= p->med)
   {
   if (s1->val > last_val(s1))
   {
   s1 = inv_rotate(s1);
   printf("[RRA]\n");
   }
   if (s1->next && s1->val > s1->next->val)
   {
   swap(s1);
   printf("[SA]\n");
   }
   else
   {	
   push(s1, s2, p);  // push
   s1 = p->a1;
   s2 = p->b1;
   printf("[PB]\n");
// p->a1 = NULL;
// p->b1 = NULL;
}
}
if (s1->val <= p->med)
{
push(s1, s2, p);  // push
s1 = p->a1;
s2 = p->b1;
// p->a1 = NULL;
// p->b1 = NULL;
printf("[PB]\n");
p->nb--;
}
else
{ 
s1 = rotate_list(s1);
printf("[RA]\n");
p->nb--;
//	printf("%d\n", p->nb);
}
}
while (!(is_sorted(s1)))
{
if (s1->next && s1->val > s1->next->val)
{
swap(s1);
printf("[SA]\n");
push(s1, s2, p);  // push
s1 = p->a1;
s2 = p->b1;
// p->a1 = NULL;
// p->b1 = NULL;
printf("[PB]\n");
}
else
{
push(s1, s2, p);  // push
s1 = p->a1;
s2 = p->b1;
// p->a1 = NULL;
// p->b1 = NULL;
printf("[PB]\n");
}	
}
print_stack(s1, s2);
}*/
