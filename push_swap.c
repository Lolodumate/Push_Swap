/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:24 by laroges           #+#    #+#             */
/*   Updated: 2023/09/29 03:22:10 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * Visualiser : https://github.com/elijahkash/push_swap_gui
 */

char	*ft_create_str(char **argv, int len) 
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 1;
	k = 0;
	if (len == 0)
		return (NULL);
	str = ft_calloc(sizeof(char), len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (argv[j])
	{
		printf("argv[j] = %s\n", argv[j]);
		while (argv[j][i])
		{
			str[k] = argv[j][i];
			k++;		
			i++;
		}
		i = 0;
		j++;
		if (argv[j])
		{
			k++;
			str[k] = ' ';
		}
	}
	return (str);
}

char	*ft_create_strjoin(char **argv, char *str, int len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 1;
	k = 0;
	if (len == 0)
		return (NULL);
	str = ft_calloc(sizeof(char), len + 2);
	if (str == NULL)
		return (NULL);
	while (argv[j])
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
		j++;
	}
	return (str);
}

t_list	*ft_convert_argv(t_list **a, char *str)
{
	int			position;
	int			i;
	int			len;
	char		*value;

	position = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		while (str[i] && !ft_isdigit(str[i]))
			i--;
		len = ft_len_number(str, i);
		value = ft_calloc(sizeof(char), len + 1);
		if (value == NULL)
			return (NULL);
		value = ft_fill_value(str, value, i, len);
		if (value == NULL)
		{
			printf("Value = NULL\n");
			free(value);
			return (NULL);
		}
		position++;
		*a = ft_create_node(a, value, position);
//		printf("unsigned int (*a)->value = %u - int = %d\n", (*a)->value, (*a)->value);
/*		if (!ft_limits((unsigned int)(*a)->value))
		{
			printf("Erreur limits d'entiers.\n");
			return (NULL);
		}
*/		i -= (len + 1);
	}
	return (*a);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	char		*str;
//	t_list	*tmp;
	int		count;

	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
	str = "0";
//	tmp = *a;
	count = 0;
	if (a == NULL || b == NULL)
		return (-1);
	*a = NULL;
	*b = NULL;
	if (argc < 2)
		ft_exit(a, b);
	if (!ft_argv_compliant(argv)) // Verifier controles sur les --, ++, etc
	{
		printf("La liste d'arguments n'est pas conforme.\n");
		ft_exit(a, b);
	}
	if (argc == 2)
		str = ft_create_str(argv, ft_len_argv(argv));
	else
		str = ft_create_strjoin(argv, str, ft_len_argv(argv));
	if (str == NULL)
		ft_exit(a, b);
//	printf("str = %sEND\n", str);
	*a = ft_convert_argv(a, str);
	free(str);
	if (*a == NULL)
	{
		printf("Value = NULL\n");
		ft_free(a, b);
		return (0);
	}
	if (!ft_duplicate(*a)) // Tester liste avec doublons (+valgrind)
		ft_exit(a, b);
//	ft_print_stack(a);
	if (ft_check_list(a))
	{
//		printf("La liste est triee.\n");
		ft_free(a, b);
		return (0);
	}

	if (ft_lstsize(*a) > 2) // Finaliser ft_sort_small_stack
	{
		ft_fill_index(a);
//		count += ft_presort(a, b);
//		ft_print_stack(a);
//		ft_print_stack(b);
		count += ft_push_bits_zero_to_b(a, b);
//		ft_print_stack(a);
//		ft_print_stack(b);
/*		if (ft_check_list(a))
			printf("La liste est triee.\n");
		else
			printf("Erreur : La liste n'est pas triee !!\n");
		printf("Nombre de coups = %d\n", count);
*/	}

/*	else
	{
		int	res;

		res = ft_sort_small_stack(a, b);
		printf("Petite liste - Resultat = %d\n", res);
		ft_print_stack(a);
		ft_print_stack(b);
		return (0);
	}
*/	
/*	ft_print_stack(a);
	ft_print_stack(b);
*/
//	if (ft_check_list(a))
//		printf("La liste est triee.\n");
//	printf("Nombre de coups = %d\n", count);



/*	tmp = ft_smallest_value(a);
	printf("Plus petite valeur - Position, index et valeur : #%d - Index = [%d] - Valeur = [%d]\n", tmp->position, tmp->index, tmp->value);
	tmp = ft_greatest_value(a);
	printf("Plus grande valeur - Position, index et valeur : #%d - Index = [%d] - Valeur = [%d]\n", tmp->position, tmp->index, tmp->value);
	ft_print_stack(*a);
	ft_print_stack(*b);
	
	ft_sort_list(b);
	printf("Pile B apres ft_sort_list(b)\n");
	ft_print_stack(*b);
*/	
//	printf("**********************************************************************************\n");
	// Test des fonctions sa, sb et ss (test OK):
/*	printf("Avant fonction sa\n");
	ft_print_stack(*a);
	printf("\nApres fonction sa. Les deux premiers elements switchent.\n");
	sa(a);
	ft_print_stack(*a);
*/	// Test des fonctions ra et rb (test OK):
/*	printf("\nAvant fonction ra\n");
	ft_print_stack(*a);
	printf("\nApres fonction ra. Le premier element passe en dernier.\n");
	ra(a);
	ft_print_stack(*a);
*/	// Test des fonctions rra et rrb
/*	printf("\nAvant fonction rra\n");
	ft_print_stack(*a);
	printf("\nApres fonction rra - Le dernier element passe en premier.\n");
	rra(a);
	ft_print_stack(*a);
*/
	// Test des fonctions pa et pb
/*	printf("\nAvant fonction pb\n");
	printf("Pile A :\n");
	ft_print_stack(*a);
	printf("Pile B :\n");
	ft_print_stack(*b);

	printf("\nApres fonction pb. Prend le premier element de a pour le mettre en haut de b.\n");
	pb(a, b);
	printf("Pile A :\n");
	ft_print_stack(*a);
	printf("Pile B :\n");
	ft_print_stack(*b);

	printf("\nApres fonction pa. Prend le premier element de b pour le mettre en haut de a.\n");
	pa(a, b);
	printf("Pile A :\n");
	ft_print_stack(*a);
	printf("Pile B :\n");
	ft_print_stack(*b);
*/	
	ft_free(a, b);
	return (0);
}
