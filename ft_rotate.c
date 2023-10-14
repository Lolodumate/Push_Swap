/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:43:01 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 18:41:16 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list_ps **a)
{
	t_list_ps		*top;
	t_list_ps		*tmp;
	t_list_ps		*new_top;

	top = *a;
	tmp = *a;
	new_top = top->next;
	top->position = 1;
	if (ft_lstsize(*a) >= 2)
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

void	rb(t_list_ps **b)
{
	t_list_ps		*top;
	t_list_ps		*tmp;
	t_list_ps		*new_top;

	top = *b;
	tmp = *b;
	new_top = top->next;
	top->position = 1;
	if (ft_lstsize(*b) >= 2)
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

void	rr(t_list_ps **a, t_list_ps **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
