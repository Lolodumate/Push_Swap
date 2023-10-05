/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:10:23 by laroges           #+#    #+#             */
/*   Updated: 2023/09/26 18:13:40 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pa(t_list **a, t_list **b) // Deplace le premier element de b sur la pile a
{
	int		pos;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp_b;

	pos = 1;
	stack_a = *a;
	stack_b = *b;
	tmp_b = *b;
	if (stack_b == NULL)
		return ;
	tmp_b = tmp_b->next;
	if (stack_a != NULL)
		pos = stack_a->position + 1;
	stack_b->next = stack_a;
	stack_b->position = pos;
	stack_b->name_stack = 'A';
	*a = stack_b;
	*b = tmp_b;
	write(1,"pa\n", 3);
}

void	pb(t_list **a, t_list **b) // Deplace le premier element de a sur la pile b
{
	int		pos;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp_a;

	pos = 1;
	stack_a = *a;
	stack_b = *b;
	tmp_a = *a;
	if (stack_a == NULL)
		return ;
	tmp_a = tmp_a->next;
	if (stack_b != NULL)
		pos = stack_b->position + 1;
	stack_a->next = stack_b;
	stack_a->position = pos;
	stack_a->name_stack = 'B';
	*b = stack_a;
	*a = tmp_a;
	write(1, "pb\n", 3);
}
