/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:07:27 by laroges           #+#    #+#             */
/*   Updated: 2023/09/29 08:39:04 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_list_and_fill_index(t_list **lst)
{
	t_list		*tmp;
	int	i;
	int	n;

	tmp = *lst;
	i = 1;
	n = 0;
	if (lst == NULL)
		return (-1);
	while (tmp)
	{
		n = tmp->value;
		tmp = tmp->next;
		if (tmp && n > tmp->value && tmp->index != 1)
		{
			tmp->index = 0;
			return (0);
		}
		if (tmp && tmp->index != 1)
		{
			i++;
			tmp->index = i;
		}
	}
	return (i);
}

// Chaque valeur se voit attribuer un index qui correspond a sa position dans l'ordre croissant de la liste
void	ft_sort_list(t_list **b)
{
	t_list		*tmp;

	tmp = *b;
	if (b == NULL)
		return ;
	while (tmp && tmp->index > 0)
	{
		rb(b);
		tmp = *b;
		printf("ft_sort_list(b) - Position de tmp = #%d\n", tmp->position);
		ft_print_stack(*b);
		if (ft_check_list_and_fill_index(b) == 0)
			sb(b);
		printf("ft_sort_list(b) - Position de tmp = #%d\n", tmp->position);
	}
}

/*
void	ft_sort_small_stack(t_list **a)
{

}
*/

/*
void	ft_sort_big_stack(t_list **a)
{

}
*/

int	ft_fill_index(t_list **a, t_list **b)
{
	int		i;
	int		pos;
	int		counter;
	t_list	*tmp;

	i = 0;
	pos = 0;
	counter = 0;
	if (a == NULL)
		return (-1);
	tmp = *a;
	pos = tmp->position;
	// Evaluer la position du plus petit nombre dans la liste et determiner quelle fonction permet de le remonter en haut de la pile le plus rapidement (ra ou rra).
	while (tmp && i < pos)
	{
		i++;
		tmp = ft_smallest_value(a);
		ft_print_stack(*a);
		tmp->index = i;
		tmp = *a;
	}
	ft_print_stack(*b);
	return (counter + i);
}

t_list	*ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	pa(a, b);
	if (tmp == NULL)
		return (NULL);
	return (ft_pa(a, b));
}

t_list	*ft_smallest_value(t_list **lst) // Test OK
{
	t_list		*tmp;
	t_list		*t_small;
	int	smallest;

	tmp = *lst;
	t_small = tmp;
	smallest = tmp->value;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && smallest > tmp->value && tmp->index == 0)
		{
			t_small = tmp;
			smallest = tmp->value;
		}
	}
	return (t_small);
}

t_list	*ft_greatest_value(t_list **lst)
{
	t_list		*tmp;
	t_list		*t_great;
	int	greatest;

	tmp = *lst;
	t_great = tmp;
	greatest = t_great->value;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && greatest < tmp->value)
		{
			t_great = tmp;
			greatest = tmp->value;
		}
	}
	return (t_great);
}
