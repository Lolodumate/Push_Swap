#include <stdio.h>
#include "push_swap.h"

int	main()
{
	int	tab[7] = {4, 0, 6, 1, 5, 2, 3};
	int	i;
	char	*res;

	i = 0;
	while (i < 7)
	{
//		printf("%s\n", ft_convert_binary(tab[i]));
		res = ft_convert_binary(tab[i]);
		printf("%s\n", res);
		free(res);
		i++;
	}
	return (0);
}
