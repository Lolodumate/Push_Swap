/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:22:30 by laroges           #+#    #+#             */
/*   Updated: 2023/09/25 15:42:18 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list		*top;
	t_list		*tmp;
	int	tmp_value;
	int	tmp_position;

	top = *a;
	tmp = top->next;
	tmp_value = 0;
	tmp_position = 0;
	if (a != NULL)
	{
		tmp_value = top->value;
		tmp_position = top->position;
		top->value = tmp->value;
		top->position = tmp->position + 1;
		tmp->value = tmp_value;
		tmp->position = tmp_position - 1;
		ft_putstr("sa\n");
	}
}

void	sb(t_list **b)
{
	t_list	*top;
	t_list	*tmp;
	int	tmp_value;
	int	tmp_position;

	top = *b;
	tmp = top->next;
	tmp_value = 0;
	tmp_position = 0;
	if (b != NULL)
	{
		tmp_value = top->value;
		tmp_position = top->position;
		top->value = tmp->value;
		top->position = tmp->position + 1;
		tmp->value = tmp_value;
		tmp->position = tmp_position - 1;
		ft_putstr("sb\n");
	}
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_putstr("ss\n");
}
