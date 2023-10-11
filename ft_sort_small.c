/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:36:20 by laroges           #+#    #+#             */
/*   Updated: 2023/10/11 20:35:56 by laroges          ###   ########.fr       */
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

int	ft_stack_sized_two(t_list **a)
{
	int		count;

	count = 0;
	if ((*a)->value > (*a)->next->value)
	{
		sa(a);
		count++;
	}
	return (count);
}

int	ft_stack_sized_three(t_list **a)
{
	int		count;

	count = 0;
	if ((*a)->index == 1)
	{
		rra(a);
		sa(a);
		count = 2;
	}
	else if ((*a)->index == 2)
	{
		if ((*a)->next->index == 1)
			sa(a);
		else
			rra(a);
		count++;
	}
	else if ((*a)->index == 3)
	{
		ra(a);
		count++;
		if (!ft_check_list(a))
		{
			sa(a);
			count++;
		}
	}
	return (count);
}

// 1. Find the greatest index et send it in the stack B.
// 2. Run of the fonction to sort three nodes.
// 3. Send back the greatest index in the stack A and place it in the bottom.
int	ft_stack_sized_four(t_list **a, t_list **b)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = ft_smallest_value_indicator(a);
	if (tmp->position == 1)
	{
		rra(a);
		pb(a, b);
		count += 2;
	}
	else if (tmp->position == 2)
	{
		rra(a);
		rra(a);
		pb(a, b);
		count += 3;
	}
	else 
	{
		if (tmp->position == 3)
		{
			sa(a);
			count++;
		}
		pb(a, b);
		count++;
	}
	ft_update_index(a, b);
	if (!ft_check_list(a))
		count += ft_stack_sized_three(a);
	pa(a, b);
	count += 2;
	return (count);
}

int	ft_stack_sized_five(t_list **a, t_list **b)
{
	int		count;
	t_list	*tmp;

	count = 0;
	if (*a == NULL)
		return (-1);
	tmp = ft_smallest_value_indicator(a);
	if (tmp->position == 5 || tmp->position == 4)
	{
		if (tmp->position == 4)
		{
			sa(a);
			count++;
		}
		pb(a, b);
		count++;
	}
	else if (tmp->position == 1 || tmp->position >= 2)
	{
		if (tmp->position >= 2)
		{
			rra(a);
			count++;
			if (tmp->position == 2)
			{
				rra(a);
				count++;
			}
		}
		rra(a);
		pb(a, b);
		count += 2;
	}
	count += ft_stack_sized_four(a, b);
	pa(a, b);
	return (count);
}

t_list	*ft_smallest_value_indicator(t_list **a)
{
	t_list	*tmp;
	t_list	*smallest_ptr;
	int		smallest;

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

void	ft_update_index(t_list **a, t_list **b)
{
	int		i;
	t_list	*tmp;

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
