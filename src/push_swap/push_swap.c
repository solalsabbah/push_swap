#include "checker.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack		*s1;

	if (ac == 1)
		return (0);
	i = 1;
	s1 = NULL;
	return (0);
	while (--ac > 0)
	{
		if (ft_isnumber(av[ac]) == 0)
		{
			printf("Usage : please only put number\n");
			return (0);
		}
		s1 = add_link(s1, ft_atoi(av[ac]));
	}
	print_stack(s1, NULL);
}
