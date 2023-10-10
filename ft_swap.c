/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:22:30 by laroges           #+#    #+#             */
/*   Updated: 2023/10/10 17:03:17 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list		*top;
	t_list		*tmp;
	int			tmp_value;
	int			tmp_position;
	int			tmp_index;

	top = *a;
	tmp = top->next;
	tmp_value = 0;
	tmp_position = 0;
	tmp_index = 0;
	if (a != NULL)
	{
		tmp_value = top->value;
		tmp_position = top->position;
		tmp_index = top->index;
		top->value = tmp->value;
		top->position = tmp->position + 1;
		top->index = tmp->index;
		tmp->value = tmp_value;
		tmp->position = tmp_position - 1;
		tmp->index = tmp_index;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **b)
{
	t_list	*top;
	t_list	*tmp;
	int		tmp_value;
	int		tmp_position;
	int		tmp_index;

	top = *b;
	tmp = top->next;
	tmp_value = 0;
	tmp_position = 0;
	tmp_index = 0;
	if (b != NULL)
	{
		tmp_value = top->value;
		tmp_position = top->position;
		tmp_index = top->index;
		top->value = tmp->value;
		top->position = tmp->position + 1;
		top->index = tmp->index;
		tmp->value = tmp_value;
		tmp->position = tmp_position - 1;
		tmp->index = tmp_index;
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

int	ft_is_greater_than(t_list **lst)
{
	int		n;
	t_list	*tmp;

	n = 0;
	if (lst == NULL || *lst == NULL)
		return (0);
	if (ft_lstsize(*lst) < 2)
		return (0);
	tmp = *lst;
	if (tmp->next == NULL)
		return (0);
	n = tmp->index;
	tmp = tmp->next;
	if (n > tmp->index)
		return (1);
	return (0);
}
