/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:43:01 by laroges           #+#    #+#             */
/*   Updated: 2023/09/20 16:52:55 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ra(t_element *a)
{
	t_element	*new_top;
	t_element	*old_top;

	new_top = a->next;
	old_top = a;
	if (a != NULL)
	{
		while (a->next != NULL)
		{
			a->position++;
			a = a->next;
		}
		a->position++;
		a->next = old_top;
		a = a->next;
		a->position = 1;
		a->next = NULL;
	}
	return (new_top);
}

t_element	*rb(t_element *b)
{
	t_element	*new_top;
	t_element	*old_top;

	new_top = b->next;
	old_top = b;
	if (b != NULL)
	{
		while (b->next != NULL)
		{
			b->position++;
			b = b->next;
		}
		b->position++;
		b->next = old_top;
		b = b->next;
		b->position = 1;
		b->next = NULL;
	}
	return (new_top);
}

void	rr(t_element *a, t_element *b)
{
	ra(a);
	rb(b);
}
