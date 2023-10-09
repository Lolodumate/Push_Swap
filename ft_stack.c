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
	{
//		printf("ft_stack.c l.44 A EFFACER - La pile a ete nettoyee.\n");
		return (NULL);
	}
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

void	ft_print_stack(t_list **lst)
{
//	char	lst_name;
	t_list	*tmp;

//	lst_name = 0;
	tmp = *lst;
	if (*lst == NULL)
	{
		printf("\nft_stack.c l.73 A EFFACER : La pile est vide.\n\n");
		return ;
	}
//	lst_name = tmp->name_stack;
	while (tmp)
	{
		printf("#%3d - Pile[%c] - I [%3d] - I_Bits %12d - I_tmp %8d - Value [%d]\n", tmp->position, tmp->name_stack, tmp->index, tmp->binary_index, tmp->index_tmp,/* tmp->smallest_value_indicator,*/ tmp->value);
		tmp = tmp->next;
		if (tmp == NULL)
			printf("ft_stack.c l.82 A EFFACER : Fin de la pile.\n\n");
	}
}
