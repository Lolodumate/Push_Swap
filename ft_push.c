/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:10:23 by laroges           #+#    #+#             */
/*   Updated: 2023/09/14 16:54:00 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_element *a, t_element *b)
{
	if (b != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *b;
		b->next = *a;
		b = tmp->next;
		free(tmp);
	}
}

void	pb(t_element *a, t_element *b)
{
	if (a != NULL)
	{
		t_element	*tmp;

		tmp = malloc(sizeof(*tmp));
		if (tmp == NULL)
			return ;
		tmp = *a;
		a->next = *b;
		a = tmp->next;
		free(tmp);
	}
}
