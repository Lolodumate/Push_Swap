/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:32:05 by laroges           #+#    #+#             */
/*   Updated: 2023/10/10 18:03:29 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
{
	t_list	*top;
	t_list	*tmp;
	int		pos;

	top = *a;
	tmp = ft_lstlast(*a);
	pos = 0;
	if (*a)
	{
		pos = top->position;
		tmp->position = pos;
		tmp->next = top;
		top = tmp;
		while (tmp)
		{
			if (tmp->position == 1)
				tmp->next = NULL;
			tmp = tmp->next;
			pos--;
			if (tmp)
				tmp->position = pos;
		}
		*a = top;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **b)
{
	t_list	*top;
	t_list	*tmp;
	int		pos;

	top = *b;
	tmp = ft_lstlast(*b);
	pos = 0;
	if (*b)
	{
		pos = top->position;
		tmp->position = pos;
		tmp->next = top;
		top = tmp;
		while (tmp)
		{
			if (tmp->position == 1)
				tmp->next = NULL;
			tmp = tmp->next;
			pos--;
			if (tmp)
				tmp->position = pos;
		}
		*b = top;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
}
