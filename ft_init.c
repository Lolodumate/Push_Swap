#include "push_swap.h"

// Calcul de longueur pour ft_convert_argv
int	ft_len_number(char *str, int i)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[i] && !ft_isdigit(str[i]))
		i--;
	while (i >= 0 && str[i] && ft_isdigit(str[i]))
	{
		len++;
		i--;
	}
	return (len);
}

// Remplissage de (*a)->value pour ft_convert_argv
char	*ft_fill_value(char *str, char *value, int i, int len)
{
	if (!str || !value || len == 0)
		return (NULL);
	len--;
	while (len >= 0 && i >= 0)
	{
		value[len] = str[i];
		i--;
		len--;
	}
	return (value);
}

t_list	*ft_create_node(t_list **a, char *value, int position)
{
	if (!a || !value)
		return (NULL);
	*a = ft_add_node(*a, (int)ft_atoi(value), position);
	(*a)->name_stack = 'A';
	free(value);
	return (*a);
}

// Verification des limites d'entiers pour ft_convert_argv
int	ft_limits(unsigned int value)
{
	if (value > 2147483647)
		return (1);
	return (0);
}

t_list	*ft_duplicate(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	if (a == NULL)
		return (NULL);
	while (a)
	{
		if (ft_check_duplicate(a->value, a) != NULL)
			return (NULL);
		a = a->next;
	}
	return (tmp);
}
