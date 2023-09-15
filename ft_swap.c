/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:22:30 by laroges           #+#    #+#             */
/*   Updated: 2023/09/14 16:56:00 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_element *a)
{
	if (a != NULL && a->next != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *a;
		a = a->next;
		a->next = tmp;
	}
}

void	sb(t_element *b)
{
	if (b != NULL && b->next != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *b;
		b = b->next;
		b->next = tmp;
	}
}

void	ss(t_element *a, t_element *b)
{
	sa(a);
	sb(b);
}
