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
int	ft_argv_compliant(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == ' ')
	{
		if (str[i] == '-' || str[i] == '+')
			if (!str[i + 1] || str[i + 1] == '-' || str[i + 1] == '+' || str[i + 1] == ' ')
				return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

t_list	*ft_convert_argv(t_list **a, char *str)
{
	int			position;
	int			i;
	int			len;
	char		*value;

	position = 0;
	i = ft_strlen(str);;
	while (i >= 0)
	{
		while (!ft_isdigit(str[i]))
			i--;
		len = 0;
		len = ft_len_number(str, i);
		value = malloc(sizeof(char) * len + 1);
		if (value == NULL)
			return (NULL);
		value = ft_fill_value(str, value, i, len); // Reprendre le ft_atoi long long de la piscine
		if (value == NULL)
		{
			printf("Value = NULL\n");
			free(value);
			return (NULL);
		}
		position++;
		*a = ft_create_node(a, value, position);
//		printf("Valeur de (*a)->value = %d\n", (*a)->value);
		i -= (len + 1);
	}
	return (*a);
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
		{
//			printf("Erreur ft_check_duplicate = NULL\n");
			return (NULL);
		}
		a = a->next;
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
//	t_list	*tmp;
	int	count;

	a = (t_list **)malloc(sizeof(t_list));
	b = (t_list **)malloc(sizeof(t_list));
//	tmp = *a;
	count = 0;
	if (a == NULL || b == NULL)
		return (-1);
	*a = NULL;
	*b = NULL;
	if (argc != 2)
		ft_exit(a, b);
	if (!ft_argv_compliant(argv[1])) // Verifier controles sur les --, ++, etc
		ft_exit(a, b);
	*a = ft_convert_argv(a, argv[1]);
	if (*a == NULL)
	{
		printf("Value = NULL\n");
		ft_free(a, b);
		return (0);
	}
	if (!ft_duplicate(*a)) // Tester liste avec doublons (+valgrind)
		ft_exit(a, b);
	if (ft_check_list(a))
	{
		ft_free(a, b);
		return (0);
	}
	if (ft_lstsize(*a) > 5) // Finaliser ft_sort_small_stack
	{
		ft_fill_index(a);
		count = ft_push_bits_zero_to_b(a, b);
		printf("Nombre de coups = %d\n", count);
		ft_print_stack(a);
		ft_print_stack(b);
	}

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
//	ft_print_stack(a);
//	ft_print_stack(b);
	
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
