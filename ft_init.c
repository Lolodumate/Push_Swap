#include "push_swap.h"

// Fonction de placement de l'index a la fin de str pour ft_convert_argv
/*
int	ft_place_index(char *str, int i)
{
	while (str[i])
		i++;
	while (!ft_isdigit(str[i]))
		i--;
	return (i);
}
*/
// Fonction de calcul de longueur pour ft_convert_argv
int	ft_len_number(char *str, int i)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (!ft_isdigit(str[i]))
		i--;
	while (ft_isdigit(str[i]))
	{
		len++;
		i--;
	}
	return (len);
}

// Fonction de remplissage de (*a)->value pour ft_convert_argv
char	*ft_fill_value(char *str, char *value, int i, int len)
{
	if (!str || !value || len == 0)
		return (NULL);
	value[len] = '\0';
	while (len - 1 >= 0)
	{
		value[len - 1] = str[i];
		i--;
		len--;
	}
//	printf("Valeur de ft_limits(ft_atoi(value)) = %d\n - Value = %s\n", ft_limits(ft_atoi(value)), value);
	if (ft_limits(ft_atoi(value)) == 0)
		return (NULL);
	return (value);
}

t_list	*ft_create_node(t_list **a, char *value, int position)
{
	if (!a || !value)
		return (NULL);
	if (value[0] != '\0')
	{
		*a = ft_add_node(*a, (int)ft_atoi(value), position);
		(*a)->name_stack = 'A';
	}
	free(value);
	return (*a);
}

// Fonction de verification des limites d'entiers pour ft_convert_argv
int	ft_limits(long long value)
{
	if (value >= -2147483648 && value <= 2147483647)
		return (1);
	return (0);
}
