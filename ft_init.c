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
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[i] && !ft_isdigit(str[i]))
		i--;
//	printf("Valeur de str[i] dans ft_len_number apres while 1 - str[%d] = %c\n", i, str[i]);
	while (i >= 0 && str[i] && ft_isdigit(str[i]))
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
	len--;
	printf("i = %d - len = %d\n", i, len);
	while (len >= 0 && i >= 0)
	{
		value[len] = str[i];
		printf("value[%d] = %c - str[%d] = %c\n", len, value[len], i, str[i]);
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

// Fonction de verification des limites d'entiers pour ft_convert_argv
int	ft_limits(long long value)
{
	if (value >= -2147483648 && value <= 2147483647)
		return (1);
	return (0);
}
