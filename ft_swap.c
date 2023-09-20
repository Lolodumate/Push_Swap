/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:22:30 by laroges           #+#    #+#             */
/*   Updated: 2023/09/20 15:30:06 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*sa(t_element *a)
{
	t_element	*top_stack;
	t_element	*tmp;
	int	e_position1;
	int	e_position2;

	top_stack = a;
	tmp = 0;
	e_position1 = a->position;
	e_position2 = 0;
	if (a != NULL && a->next != NULL)
	{
		a = a->next;
		e_position2 = a->position;
		a->position = e_position1;
		tmp = a->next;
		a->next = top_stack;
		top_stack = a;
		a = a->next;
		a->position = e_position2;
		a->next = tmp;
	}
	return (top_stack);
}

t_element	*sb(t_element *b)
{
	t_element	*top_stack;
	t_element	*tmp;
	int	e_position1;
	int	e_position2;

	top_stack = b;
	tmp = 0;
	e_position1 = b->position;
	e_position2 = 0;
	if (b != NULL && b->next != NULL)
	{
		b = b->next;
		e_position2 = b->position;
		b->position = e_position1;
		tmp = b->next;
		b->next = top_stack;
		top_stack = b;
		b = b->next;
		b->position = e_position2;
		b->next = tmp;
	}
	return (top_stack);
}

void	ss(t_element *a, t_element *b)
{
	sa(a);
	sb(b);
}
