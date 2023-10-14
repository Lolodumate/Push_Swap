/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:36:20 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 18:42:19 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sized_two(t_list_ps **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	ft_stack_sized_three(t_list_ps **a)
{
	if ((*a)->index == 1)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->index == 2)
	{
		if ((*a)->next->index == 1)
			sa(a);
		else
			rra(a);
	}
	else if ((*a)->index == 3)
	{
		ra(a);
		if (!ft_check_list(a))
			sa(a);
	}
}

// 1. Find the greatest index et send it in the stack B.
// 2. Run of the fonction to sort three nodes.
// 3. Send back the greatest index in the stack A and place it in the bottom.
void	ft_stack_sized_four(t_list_ps **a, t_list_ps **b)
{
	t_list_ps	*tmp;

	tmp = ft_smallest_value_indicator(a);
	if (tmp->position == 1)
		rra(a);
	else if (tmp->position == 2)
	{
		rra(a);
		rra(a);
	}
	else if (tmp->position == 3)
		sa(a);
	pb(a, b);
	ft_update_index(a, b);
	if (!ft_check_list(a))
		ft_stack_sized_three(a);
	pa(a, b);
}

void	ft_stack_sized_five(t_list_ps **a, t_list_ps **b)
{
	t_list_ps	*tmp;

	if (*a == NULL)
		return ;
	tmp = ft_smallest_value_indicator(a);
	if (tmp->position == 5 || tmp->position == 4)
	{
		if (tmp->position == 4)
			sa(a);
		pb(a, b);
	}
	else if (tmp->position == 1 || tmp->position >= 2)
	{
		if (tmp->position >= 2)
		{
			rra(a);
			if (tmp->position == 2)
				rra(a);
		}
		rra(a);
		pb(a, b);
	}
	ft_stack_sized_four(a, b);
	pa(a, b);
}
