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
/*
int	ft_do_swap(t_list **a, t_list **b)
{
	int		check_a;
	int		check_b;
	t_list	*tmp_a;
	t_list	*tmp_b;

	check_a = 0;
	check_b = 0;
	tmp_a = *a;
	tmp_b = *b;
	if (*a == NULL || *b == NULL)
		return (0);
	check_a = tmp_a->binary_index;
	check_b = tmp_b->binary_index;
	tmp_a = tmp_a->next;
	tmp_b = tmp_b->next;
	if (check_a < tmp_a->binary_index)
		if (check_b < tmp_b->binary_index)
		{
			ss(a, b);
			return (1);
		}
	return (0);
		
}

int	ft_is_greater_than(t_list **lst)
{
	int		n;
	t_list	*tmp;

	n = 0;
	if (lst == NULL || *lst == NULL)
		return (0);
	tmp = *lst;
	if (tmp->next == NULL)
		return (0);
	n = tmp->value;
	tmp = tmp->next;
	if (n > tmp->value)
		return (1);
	return (0);

}*/
