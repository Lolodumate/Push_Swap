#include "push_swap.h"

// sub foncton for ft_build_stack

char	*ft_create_value(char *str, int i,  int len)
{
	char	*tmp;

	tmp = ft_calloc(sizeof(char), len + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_fill_value(str, tmp, i, len);
	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
