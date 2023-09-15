/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:29:24 by laroges           #+#    #+#             */
/*   Updated: 2023/09/15 20:06:06 by laroges          ###   ########.fr       */
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

/*
t_element	*ft_check_init_a(t_element *e)
{
	int		i;
	int		count;
	int		sign;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			a = ft_add_element(a);	
			sign = 1;
			while (ft_isdigit(str[i]))
			{
				if (str[i] == '-' || str[i] == '+')
				{
					if (str[i] = '-')
						sign = -1;
					i++;
				}
				a->value += (str[i] - '0'); 
				i++;
				if (ft_isdigit(str[i]))
					a->value *= 10;
				else if (!str[i])
				{
					a->value *= sign;
					a->position++;
				}
			}
		}
		i++;
	}
	return (a);
}
*/

t_element	*push_swap(t_element *a)
{
	t_element	*tmp;

	tmp = a;
	if (a == NULL)
		return (NULL);
	while (a)
	{
		printf("Valeur de tmp->value = %d\n", a->value);
		if (ft_check_duplicate(a->value, a) != NULL) // Fonction a priori OK. Faire tests complementaires.
		{
			ft_putstr("Error.\n");
			printf("La valeur %d figure plusieurs fois dans la liste.\n", a->value);
			return (NULL);
		}
		a = a->next;
		// Ajouter une verification sur les limites d'entiers INT_MIN et INT_MAX.
	}
	return (tmp);
}

int	main(int argc, char **argv)
{
	t_element	*e;
	t_element	*tmp;

	e = NULL;
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (-1);
	if (argc == 2)
		if (!ft_argv_compliant(argv[1])) // Fonction a corriger : retour incorrect sur les doubles signes --, ++, -+, etc...
			return (-1);
	if (argc != 2)
	{
		ft_putstr("Error : le nombre d'argument doit etre de 1.\n");
		return (0);
	}
	e = ft_convert_argv(e, argv[1]);
	tmp = e;
	push_swap(e);
	while (tmp != NULL)
	{
		printf("Position = %d - Value = %d\n", tmp->position, tmp->value);
		tmp = ft_free_top_stack(tmp);
		if (tmp == NULL)
			printf("Fin de la pile.\n");
	}
	if (tmp == NULL)
		printf("La pile est vide.\n");
	return (0);
}
