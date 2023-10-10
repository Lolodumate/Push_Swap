/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:36:20 by laroges           #+#    #+#             */
/*   Updated: 2023/10/10 22:25:48 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sub fonction for ft_smallest_value
// Browse the list until it finds an index == 0
t_list	*ft_loop_smallest_ptr(t_list **lst)
{
	t_list	*tmp;
	t_list	*t_small;
	int		i;

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
t_list	*ft_loop_find_smallest_value(t_list **lst, t_list *t_small, int smallest)
{
	t_list	*tmp;

	tmp = *lst;
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
