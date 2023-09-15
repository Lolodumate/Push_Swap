/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:32:05 by laroges           #+#    #+#             */
/*   Updated: 2023/09/14 16:54:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_element *a)
{
	if (a != NULL && a->next != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *a;
		while (a->next != NULL)
			a = a->next;
		a->next = *tmp;
		a = NULL;
		free(tmp);
	}
}

void	rrb(t_element *b)
{
	if (b != NULL && b->next != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *b;
		while (b->next != NULL)
			b = b->next;
		b->next = *tmp;
		b = NULL;
		free(tmp);
	}
}

void	rrr(t_element *a, t_element *b)
{
	rra(a);
	rrb(b);
}
