/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:24 by laroges           #+#    #+#             */
/*   Updated: 2023/10/11 21:19:56 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * Visualiser : https://github.com/elijahkash/push_swap_gui
 */

// Create a string with only one argument
char	*ft_create_str(char **argv, int len)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (len == 0)
		return (NULL);
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (argv[1][i])
	{
		str[k] = argv[1][i];
		k++;
		i++;
	}
	return (str);
}

// Create one single string with several arguments
char	*ft_create_strjoin(char **argv, int len)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	str = ft_calloc(sizeof(char), len + 2);
	if (str == NULL)
		return (NULL);
	str[len + 1] = '\0';
	while (argv[++j])
	{
		while (argv[j][i])
		{
			str[k] = argv[j][i];
			k++;
			i++;
		}
		str[k] = ' ';
		k++;
		i = 0;
	}
	return (str);
}

t_list	*ft_build_stack(t_list **a, t_list **b, char *str)
{
	int			position;
	int			i;
	int			len;
	char		*value;

	position = 0;
	i = ft_strlen(str) - 1;
	value = NULL;
	while (i >= 0)
	{
		while (str[i] && !ft_isdigit(str[i]))
			i--;
		len = ft_len_number(str, i);
		value = ft_create_value(str, i, len);
		position++;
		*a = ft_create_node(a, value, position);
		if (*a == NULL)
		{
			free(value);
			free(str);
			ft_exit(a, b);
		}
		i -= (len + 1);
	}
	return (*a);
}

char	*ft_build_str(int argc, char **argv)
{
	char	*str;

	if (!ft_argv_compliant(argv))
		return (NULL);
	if (argc == 2 && ft_len_argv(argv) > 0)
		str = ft_create_str(argv, ft_len_argv(argv));
	else if (argc > 2 && ft_len_argv(argv) > 0)
		str = ft_create_strjoin(argv, ft_len_argv(argv));
	else
		str = NULL;
	return (str);
}

// Test : make m && valgrind ./push_swap 5 3 4 6 7 8 1 2 9 0-0000000 10
int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	int		count;

	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	count = 0;
	if (a == NULL || b == NULL)
		return (-1);
	*a = NULL;
	*b = NULL;
	if (argc < 2)
	{
		free(a);
		free(b);
		return (0);	
	}
	*a = ft_init_stack_a(argc, argv, a, b);
	if (!ft_check_list(a))
	{
		if (ft_lstsize(*a) > 5) // Finaliser ft_sort_small_stack
			count += ft_push_bits_zero_to_b(a, b);
		else
			count += ft_sort_small_stack(a, b);
	}
/*	printf("Nombre de coups = %d\n", count);
	if (ft_check_list(a))
		printf("La liste est triee.\n");
*/	ft_free(a, b);
	return (0);
}
