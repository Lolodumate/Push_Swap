/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:43:01 by laroges           #+#    #+#             */
/*   Updated: 2023/09/25 18:14:59 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list		*top;
	t_list		*tmp;
	t_list		*new_top;

	top = *a;
	tmp = *a;
	new_top = top->next;
	top->position = 1;
	if (a)
	{
		while (tmp)
		{
			if (tmp->next == NULL)
			{
				tmp->next = top;
				tmp = tmp->next;
				tmp->next = NULL;
				*a = new_top;
				break ;
			}
			tmp = tmp->next;
			tmp->position++;
		}
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **b)
{
	t_list		*top;
	t_list		*tmp;
	t_list		*new_top;

	top = *b;
	tmp = *b;
	new_top = top->next;
	top->position = 1;
	if (b)
	{
		while (tmp)
		{
			if (tmp->next == NULL)
			{
				tmp->next = top;
				tmp = tmp->next;
				tmp->next = NULL;
				*b = new_top;
				break ;
			}
			tmp = tmp->next;
			tmp->position++;
		}
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
