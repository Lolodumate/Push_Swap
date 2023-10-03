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
	{
		ft_putstr("push_swap.c l.30 A EFFACER - Le format de la liste est conforme.\n");
		return (1);
	}
	ft_putstr("push_swap.c l.33 A EFFACER - Error : le format de la liste n'est pas conforme.\n");
	return (0);
}

t_list	*ft_convert_argv(t_list *e, char *str)
{
	int			i;
	int			j;
	int			len;
	int			position;
	char		*value;

	i = 0;
	position = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	i--;
	while (str[i] && i >= 0)
	{
		len = 0;
		j = 0;
		while (str[i] && !ft_isdigit(str[i]))
			i--;
		while (str[i] && ft_isdigit(str[i]) && i >= 0)
		{
			len++;
			i--;
		}
		i++;
		value = malloc(sizeof(char) * len + 1);
		if (value == NULL)
			return (NULL);
		while (ft_isdigit(str[i + j]) && j < len)
		{
			value[j] = str[i + j];
			j++;
		}
		value[j] = '\0';
		position++;
		if (value[0] != '\0')
		{
			e = ft_add_node(e, ft_atoi(value), position);
			e->name_stack = 'A';
		}
		free(value);
		i--;
	}
	return (e);
}

t_list	*push_swap(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	if (a == NULL)
		return (NULL);
	while (a)
	{
		if (ft_check_duplicate(a->value, a) != NULL) // Fonction a priori OK. Faire tests complementaires.
		{
			ft_putstr("Error.\n");
			printf("push_swap l.97 A EFFACER - La valeur %d figure plusieurs fois dans la liste.\n", a->value);
			return (NULL);
		}
		a = a->next;
		// Ajouter une verification sur les limites d'entiers INT_MIN et INT_MAX.
		// Ajouter une verification sur l'ordre des entiers. S'ils sont deja ordonnes, alors fin du programme.
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
	if (argc == 2)
		if (!ft_argv_compliant(argv[1])) // Fonction a corriger : retour incorrect sur les doubles signes --, ++, -+, etc...
			return (-1);
	if (argc != 2)
	{
		ft_putstr("Error : le nombre d'argument doit etre de 1.\n");
		return (0);
	}
	*a = ft_convert_argv(*a, argv[1]);
	if (*a == NULL)
	{
		free(a);
		free(b);	
	}
	if (push_swap(*a))
		ft_print_stack(a);
	if (ft_check_list_and_fill_index(a))
	{
		printf("La liste est triee.\n");
		ft_free_stack(*a);
		free(a);
		ft_free_stack(*b);
		free(b);
		return (0);
	}

	ft_fill_index(a);
/*	ft_print_stack(a);
	ft_print_stack(b);
*/
	count = ft_push_zero(a, b);
	ft_print_stack(a);
	
	if (ft_check_list_and_fill_index(a))
		printf("La liste est triee.\n");
	printf("Nombre de coups = %d\n", count);

/*	tmp = ft_smallest_value(a);
	printf("Plus petite valeur - Position, index et valeur : #%d - Index = [%d] - Valeur = [%d]\n", tmp->position, tmp->index, tmp->value);
	tmp = ft_greatest_value(a);
	printf("Plus grande valeur - Position, index et valeur : #%d - Index = [%d] - Valeur = [%d]\n", tmp->position, tmp->index, tmp->value);
	ft_print_stack(*a);
	ft_print_stack(*b);
	
	ft_sort_list(b);
	printf("Pile B apres ft_sort_list(b)\n");
	ft_print_stack(*b);
*/	printf("**********************************************************************************\n");
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
	printf("Nettoyage Pile A : ");
	ft_free_stack(*a);
	free(a);
	printf("Nettoyage Pile B : ");
	ft_free_stack(*b);
	free(b);
	return (0);
}
