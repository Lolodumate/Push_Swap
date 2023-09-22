/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:10:23 by laroges           #+#    #+#             */
/*   Updated: 2023/09/22 15:42:31 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_element	*pa(t_element *a, t_element *b) // Deplace le premier element de b sur la pile a
{
	int		e_position;

	e_position = 0;
	if (b == NULL)
		return (NULL);
	if (a == NULL)
		e_position = 1;
	else
		e_position = a->position + 1;
	a = ft_add_element(a, b->value, e_position);
	return (a);
}

t_element	*pb(t_element *a, t_element *b) // Deplace le premier element de a sur la pile b
{
	int		e_position;

	e_position = 0;
	if (a == NULL)
		return (NULL);
	if (b == NULL)
		e_position = 1;
	else
		e_position = b->position + 1;
	b = ft_add_element(b, a->value, e_position);
	return (b);
}

t_element	*ft_free_top_stack(t_element *e)
{
	t_element	*tmp;

	if (e == NULL)
		return (NULL);
	tmp = e->next;
	free(e);
	return (tmp);
}
