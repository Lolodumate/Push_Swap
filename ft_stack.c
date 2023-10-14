/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:12:47 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 21:30:52 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_add_node(t_list_ps *lst, int e_value, int e_position)
{
	t_list_ps	*new;

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

t_list_ps	*ft_free_stack(t_list_ps *lst)
{
	t_list_ps	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst->next;
	free(lst);
	return (ft_free_stack(tmp));
}

t_list_ps	*ft_check_duplicate(int value, t_list_ps *a)
{
	t_list_ps	*tmp;

	tmp = a->next;
	if (tmp == NULL)
		return (NULL);
	if (value == tmp->value)
		return (tmp);
	return (ft_check_duplicate(value, tmp));
}

int	ft_lstsize(t_list_ps *lst)
{
	int		size;

	size = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list_ps	*ft_lstlast(t_list_ps *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
