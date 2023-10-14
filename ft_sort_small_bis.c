/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:40:56 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 22:16:42 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sub fonction for ft_smallest_value
// Browse the list until it finds an index == 0
t_list_ps	*ft_loop_smallest_ptr(t_list_ps **lst)
{
	t_list_ps	*tmp;
	t_list_ps	*t_small;
	int			i;

	tmp = *lst;
	t_small = *lst;
	i = 0;
	while (t_small && t_small->index != 0)
	{
		i++;
		if (t_small->next)
			t_small = t_small->next;
		if (t_small->index == 1)
			t_small->smallest_value_indicator = 1;
		if (i == tmp->position)
		{
			t_small->index = tmp->position;
			t_small->smallest_value_indicator = 1;
			t_small = t_small->next;
			return (t_small);
		}
	}
	return (t_small);
}

// Sub fonction for ft_smallest_value
// Browse the whole list to find the smallest value with index == 0
t_list_ps	*ft_find_smallest_value(t_list_ps **lst, t_list_ps *t_small, int s)
{
	t_list_ps	*tmp;

	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && s > tmp->value && tmp->index == 0)
		{
			t_small->smallest_value_indicator = 0;
			t_small = tmp;
			s = tmp->value;
			t_small->smallest_value_indicator = 1;
		}
	}
	if (tmp == NULL && t_small->index != 0)
		t_small = NULL;
	return (t_small);
}

t_list_ps	*ft_smallest_value_indicator(t_list_ps **a)
{
	t_list_ps	*tmp;
	t_list_ps	*smallest_ptr;
	int			smallest;

	tmp = *a;
	smallest_ptr = *a;
	if (tmp == NULL)
		return (NULL);
	smallest = tmp->value;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && smallest > tmp->value)
		{
			smallest = tmp->value;
			smallest_ptr = tmp;
		}
	}
	smallest_ptr->smallest_value_indicator = 1;
	return (smallest_ptr);
}

void	ft_update_index(t_list_ps **a, t_list_ps **b)
{
	int			i;
	t_list_ps	*tmp;

	i = 1;
	tmp = *a;
	if (*a && *b && ft_lstsize(*b) == 2)
		i = 2;
	while (tmp)
	{
		tmp->index -= i;
		tmp = tmp->next;
	}
}
