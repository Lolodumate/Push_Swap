/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:32:05 by laroges           #+#    #+#             */
/*   Updated: 2023/09/20 17:39:27 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*rra(t_element *a)
{
	t_element	*final_element;
	t_element	*top_stack;
	int	e_position;

	final_element = a;
	top_stack = a;
	e_position = a->position + 1;
	if (a != NULL && a->next != NULL)
	{
		while (a->next != NULL)
			a = a->next;
		final_element = a;
		a->next = top_stack;
		a->position = e_position;
		top_stack = a;
		while (a->next != final_element)
		{
			a->position--;
			a = a->next;
		}
		a->position--;
		a->next = NULL;
	}
	return (top_stack);
}

t_element	*rrb(t_element *b)
{
	t_element	*final_element;
	t_element	*top_stack;
	int	e_position;


	final_element = b;
	top_stack = b;
	e_position = b->position + 1;
	if (b != NULL && b->next != NULL)
	{
		while (b->next != NULL)
			b = b->next;
		final_element = b;
		b->next = top_stack;
		b->position = e_position;
		top_stack = b;
		while (b->next != final_element)
			b = b->next;
		b->position--;
		b->next = NULL;
	}
	return (top_stack);
}

void	rrr(t_element *a, t_element *b)
{
	rra(a);
	rrb(b);
}
