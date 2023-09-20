/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:10:23 by laroges           #+#    #+#             */
/*   Updated: 2023/09/20 20:58:14 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void	pa(t_element *a, t_element *b)
{
	t_element	*tmp;

	if (b != NULL)
	{
		tmp = b;
		b->next = a;
		b = tmp->next;
		ft_update_position(a, b);	
	}
}
*/
void	pb(t_element *a, t_element *b)
{
	t_element	*tmp;
	t_element	*element_b;
	int	e_position;

	tmp = a;
	e_position = 0;
	if (!b)
	{
		element_b = malloc(sizeof(*element_b));
		if (element_b == NULL)
			return ;
		b = element_b;
		b->position = 0;
	}
	if (a != NULL)
	{
		e_position = b->position + 1; // b n'existe pas.
		a->next = b;
		a = tmp->next;
		a->position = e_position;
	}
}
