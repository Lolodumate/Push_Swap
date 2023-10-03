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
		if (tmp && n > tmp->value)
			return (0);
	}
	return (i);
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

void	ft_fill_index(t_list **a)
{
	int		i;
	int	bits;
	int	pos;
	t_list	*tmp;

	i = 0;
	pos = 0;
	if (a == NULL)
		return ;
	tmp = *a;
	pos = tmp->position;
	while (tmp && i < pos)
	{
		tmp = ft_smallest_value(a);
		i++;
		tmp->index = i;
		tmp->smallest_value_indicator = 0;
		bits = ft_convert_binary(i);
		tmp->binary_index = bits;
		tmp->index_tmp = bits;
		tmp = *a;
	}
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

t_list	*ft_smallest_value(t_list **lst)
{
	t_list		*tmp;
	t_list		*t_small;
	int	smallest;
	int	i;

	tmp = *lst;
	t_small = *lst;
	smallest = 0;
	i = 0;
	while (t_small && t_small->index != 0)
	{
		i++;
		if (t_small->next)
			t_small = t_small->next;
		else
		{
			t_small->smallest_value_indicator = 1;
			break ;
		}
	}
	if (i == tmp->position)
	{
		t_small->index = tmp->position;
		t_small->smallest_value_indicator = 1;
		t_small = t_small->next;
		return (t_small);
	}
	if (t_small == NULL)
		return (NULL);
	smallest = t_small->value;
	t_small->smallest_value_indicator = 1;
	ft_print_stack(lst);
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && smallest > tmp->value && tmp->index == 0)
		{
			t_small->smallest_value_indicator = 0;
			t_small = tmp;
			smallest = tmp->value;
			t_small->smallest_value_indicator = 1;
		}
	}
	if (tmp == NULL && t_small->index != 0)
		t_small = NULL;
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
	t_great->greatest_value_indicator = 1;
	return (t_great);
}
