/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:24 by laroges           #+#    #+#             */
/*   Updated: 2023/09/22 15:58:55 by laroges          ###   ########.fr       */
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
		return (1);
	ft_putstr("Error : le format de la liste n'est pas conforme.\n");
	return (0);
}

t_element	*ft_convert_argv(t_element *e, char *str)
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
			e = ft_add_element(e, ft_atoi(value), position);
		free(value);
		i--;
	}
	return (e);
}

t_element	*push_swap(t_element *a)
{
	t_element	*tmp;

	tmp = a;
	if (a == NULL)
		return (NULL);
	while (a)
	{
		printf("Position #%d - [%d]\n", a->position, a->value);
		if (ft_check_duplicate(a->value, a) != NULL) // Fonction a priori OK. Faire tests complementaires.
		{
			ft_putstr("Error.\n");
			printf("La valeur %d figure plusieurs fois dans la liste.\n", a->value);
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
	t_element	*a;
	t_element	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
		if (!ft_argv_compliant(argv[1])) // Fonction a corriger : retour incorrect sur les doubles signes --, ++, -+, etc...
			return (-1);
	if (argc != 2)
	{
		ft_putstr("Error : le nombre d'argument doit etre de 1.\n");
		return (0);
	}
	a = ft_convert_argv(a, argv[1]);
	// Test des fonctions sa, sb et ss :
	printf("Avant fonction sa\n");
	ft_print_stack(a);
	printf("\nApres fonction sa. Les deux premiers elements switchent.\n");
	a = sa(a);
	ft_print_stack(a);
	// Test des fonctions pa et pb :
	printf("\nAvant fonction ra\n");
	ft_print_stack(a);
	printf("\nApres fonction ra. Le premier element passe en dernier.\n");
	a = ra(a);
	ft_print_stack(a);
	// Test des fonctions rra et rrb
	printf("\nAvant fonction rra\n");
	ft_print_stack(a);
	printf("\nApres fonction rra - Le dernier element passe en premier.\n");
	a = rra(a);
	ft_print_stack(a);
	// Test des fonctions pa et pb
	printf("\nAvant fonction pb\n");
	printf("Pile A :\n");
	ft_print_stack(a);
	printf("Pile B :\n");
	ft_print_stack(b);
	printf("\nApres fonction pb. Prend le premier element de a pour le mettre en haut de b.\n");
	b = pb(a, b);
	a = ft_free_top_stack(a);
	printf("Pile A :\n");
	ft_print_stack(a);
	printf("Pile B :\n");
	ft_print_stack(b);
	printf("\nApres fonction pa. Prend le premier element de b pour le mettre en haut de a.\n");
	a = pa(a, b);
	b = ft_free_top_stack(b);
	printf("Pile A :\n");
	ft_print_stack(a);
	printf("Pile B :\n");
	ft_print_stack(b);
	
	a = ft_free_stack(a);
	b = ft_free_stack(b);
	return (0);
}
