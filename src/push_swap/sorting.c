#include "checker.h"

void		split_stack(t_param *p, t_stack *s1, t_stack *s2) // one way to sort the stack using only RA && RRA && PB && PA
{
	int med;
	int min;

	med = median_stack(p, s1);
	// tant que s1 est trie que s2 est vide
	
	while (mean_value(s1) > med)
	while (!is_sorted(s1) && nb_elem(s1) > nb_elem(s2))
	{
		if (s1 && s1->val <= med)
		{
			push(s1, s2, p);  // PB
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
		}
		else 
		{
			s1 = rotate_list(s1);
			printf("[RA]\n");
		}
	}
	//med = median_stack(p, s2);
	min = min_value(s1, p);
	while (s2 && s2->next != NULL)
	{
		if (s2->val > min) 
		{
			push(s2, s1, p);  // PB
			s2 = p->a1;
			s1 = p->b1;
			printf("[PA]\n");
		}
		else
		{
			s2 = rotate_list(s2);
			printf("[RB]\n");
		}
	}
	print_stack(s1, s2);
}

/*void		split_stack(t_param *p, t_stack *s1, t_stack *s2) // one way to sort the stack using only RA && RRA && PB && PA
{
	int min;
	int a;

	a = 0;
	while (is_sorted(s1) && s1->next && last_val(s1) <= s1->next->val)
	{
		if (!s2)
		{	
			push(s1, s2, p);  // push
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
			a++;
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
		a++;
		//	}
	}
	min = min_value(s1, p);
	while (s1->val != min || !is_sorted(s1))
	{
		if (s1->next && s1->next->val == min)
		{
			swap(s1);
			printf("[SA]\n");
			a++;
		}
		else if (p->sens == 0 && s1->val != min)
		{
			s1 = rotate_list(s1);
			printf("[RA]\n");
			a++;
		}
		else
		{
			s1 = inv_rotate(s1);
			printf("[RRA]\n");
			a++;
		}
		if (s1->val == min && !is_sorted(s1))
		{
			push(s1, s2, p);  // push
			s1 = p->a1;
			s2 = p->b1;
			printf("[PB]\n");
			a++;
			min = min_value(s1, p);
		}
	}
	while (s2)
	{
		push(s2, s1, p);  // push
		s2 = p->a1;
		s1 = p->b1;
		printf("[PA]\n");
			a++;
	}
	printf("compteur : %d\n", a);
//	print_stack(s1, s2);
}*/
