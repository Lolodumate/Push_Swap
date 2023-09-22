/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:12:47 by laroges           #+#    #+#             */
/*   Updated: 2023/09/22 15:43:52 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_add_element(t_element *e, int e_value, int e_position)
{
	t_element	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (tmp == NULL)
		return (NULL);
	tmp->value = e_value;
	tmp->position = e_position;
	tmp->index = 0;
	tmp->count = 0;
	tmp->next = e;
	return (tmp);
}

t_element	*ft_free_stack(t_element *e)
{
	t_element	*tmp;

	if (e == NULL)
		return (NULL);
	tmp = e->next;
	free(e);
	if (tmp == NULL)
		printf("La pile a ete nettoyee.\n");
	return (ft_free_stack(tmp));
}

t_element	*ft_check_duplicate(int value, t_element *e)
{
	t_element	*tmp;

	tmp = e->next;
	if (tmp == NULL)
		return (NULL);
	if (value == tmp->value)
		return (tmp);
	return (ft_check_duplicate(value, tmp));
}
