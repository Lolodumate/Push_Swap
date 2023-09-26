/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:07:27 by laroges           #+#    #+#             */
/*   Updated: 2023/09/26 21:28:57 by laroges          ###   ########.fr       */
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
void	ft_pb(t_list **a, t_list **b)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;
	int	nb_values;
	int	n;

	stack_a = *a;
	stack_b = *b;
	i = 0;
	nb_values = stack_a->position;
	n = 0;
	while (stack_a && i < nb_values)
	{
		if (stack_a && stack_a->index > 0)
			ra(a);
		else
		{
			pb(a, b);
			stack_b = *b;
			n = stack_b->value;
			stack_b = stack_b->next;
			if (stack_b && n > stack_b->value)
			{
				stack_b->index = 0;
				sb(b);
				ft_smallest_value(b);
			}
			ft_check_list_and_fill_index(b);
		}
		stack_a = *a;
		i++;
	}
}

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
		ft_check_list_and_fill_index(b);
		printf("ft_sort_list(b) - Position de tmp = #%d\n", tmp->position);
	}
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
		if (tmp && smallest > tmp->value)
		{
			t_small = tmp;
			smallest = tmp->value;
		}
	}
	t_small->index = 1;
	return (t_small);
}

t_list	*ft_greatest_value(t_list **lst) // Test OK
{
	t_list		*tmp;
	t_list		*t_great;
	int	greatest;
//	int	i;

	tmp = *lst;
	t_great = tmp;
	greatest = tmp->value;
//	i = tmp->position;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && greatest < tmp->value)
		{
			t_great = tmp;
			greatest = tmp->value;
		}
	}
//	t_great->index = i;
	return (t_great);
}
/*
int	ft_sort(t_list **a, t_list **b)
{
	while (ft_check_list(*a) == 0)
	{
		
	}
}*/
