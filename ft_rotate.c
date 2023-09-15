/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:43:01 by laroges           #+#    #+#             */
/*   Updated: 2023/09/14 16:55:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_element *a)
{
	if (a != NULL && a->next != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *a;
		tmp->next = NULL;
		a = a->next;
		while (a->next != NULL)
			a = a->next;
		a->next = *tmp;
		free(tmp);
	}
}

void	rb(t_element *b)
{
	if (b != NULL && b->next != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *b;
		tmp->next = NULL;
		b = b->next;
		while (b->next != NULL)
			b = b->next;
		b->next = *tmp;
		free(tmp);
	}
}

void	rr(t_element *a, t_element *b)
{
	ra(a);
	rb(b);
}
