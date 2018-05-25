#include "checker.h"

void    sort_three(t_stack *s1)
{
        if(!is_sorted(s1))
        {
                if (s1->val < s1->next->val && s1->val < s1->next->next->val)
                {
                        printf("[RRA]\n");
                        printf("[SA]\n");
                }
                else if (s1->val > s1->next->val && s1->next->val > s1->next->next->val)
                {
                        printf("[SA]\n");
                        printf("[RRA]\n");
                }
                else if (s1->val > s1->next->next->val && s1->next->val < s1->next->next->val)
                {
                        printf("[RA]\n");
                }
                else if (s1->val < s1->next->next->val && s1->next->val < s1->val)
                {
                        printf("[SA]\n");
                }
                else
                        printf("[RRA]\n");
        }
}

void    sort_two(t_stack *s1)
{
        if(!is_sorted(s1))
        {
                swap(s1);
                printf("[SA]\n");
        }

}
