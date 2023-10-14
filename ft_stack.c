/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:12:47 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 15:00:06 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_add_node(t_list *lst, int e_value, int e_position)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		ft_free_stack(new);
		return (NULL);
	}
	new->value = e_value;
	new->position = e_position;
	new->smallest_value_indicator = 0;
	new->greatest_value_indicator = 0;
	new->index = 0;
	new->index_tmp = 0;
	new->count = 0;
	new->binary_index = 0;
	new->len_binary = 0;
	new->lock = 0;
	new->next = lst;
	return (new);
}

t_list	*ft_free_stack(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst->next;
	free(lst);
	return (ft_free_stack(tmp));
}

t_list	*ft_check_duplicate(int value, t_list *a)
{
	t_list	*tmp;

	tmp = a->next;
	if (tmp == NULL)
		return (NULL);
	if (value == tmp->value)
		return (tmp);
	return (ft_check_duplicate(value, tmp));
}
