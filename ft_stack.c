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
	{
		ft_free_stack(e);
		return (NULL);
	}
	tmp->value = e_value;
	tmp->position = e_position;
	tmp->smallest_value_indicator = 0;
	tmp->greatest_value_indicator = 0;
	tmp->index = 0;
	tmp->index_tmp = 0;
	tmp->count = 0;
	tmp->binary_index = 0;
	tmp->len_binary = 0;
	tmp->next = e;
	return (tmp);
}

t_list	*ft_free_stack(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
	{
		printf("ft_stack.c l.44 A EFFACER - La pile a ete nettoyee.\n");
		return (NULL);
	}
	tmp = lst->next;
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

void	ft_print_stack(t_list **lst)
{
	char	lst_name;
	t_list	*tmp;

	lst_name = 0;
	tmp = *lst;
	if (tmp == NULL)
	{
		ft_putstr("\nft_stack.c l.73 A EFFACER : La pile est vide.\n\n");
		return ;
	}
	lst_name = tmp->name_stack;
	while (tmp)
	{
		printf("#%5d - Pile [%c] - Index [%5d] - I_Binaire %8d - I_tmp %8d - Valeur [%d]\n", tmp->position, tmp->name_stack, tmp->index, tmp->binary_index, tmp->index_tmp, tmp->value);
		tmp = tmp->next;
		if (tmp == NULL)
			printf("ft_stack.c l.82 A EFFACER : Fin de la pile %c.\n\n", lst_name);
	}
}
