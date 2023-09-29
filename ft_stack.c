/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:12:47 by laroges           #+#    #+#             */
/*   Updated: 2023/09/29 00:45:14 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_add_node(t_list *e, int e_value, int e_position)
{
	t_list	*tmp;
	
	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->ptr_node = tmp;
	tmp->value = e_value;
	tmp->position = e_position;
	tmp->index = 0;
	tmp->count = 0;
	tmp->next = e;
	return (tmp);
}

t_list	*ft_free_stack(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
	{
		printf("La pile a ete nettoyee.\n");
		return (NULL);
	}
	if (tmp)
		tmp = tmp->next;
	free(lst);
	return (ft_free_stack(tmp));
}

t_list	*ft_check_duplicate(int value, t_list *e)
{
	t_list	*tmp;

	tmp = e->next;
	if (tmp == NULL)
		return (NULL);
	if (value == tmp->value)
		return (tmp);
	return (ft_check_duplicate(value, tmp));
}
