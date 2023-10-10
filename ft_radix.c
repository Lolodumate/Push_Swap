/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:34:41 by laroges           #+#    #+#             */
/*   Updated: 2023/10/10 20:47:45 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Size of each binary index
void	ft_len_binary(t_list **a)
{
	int		len;
	int		i;
	t_list	*tmp;

	len = 0;
	i = 0;
	if (a == NULL)
		return ;
	tmp = *a;
	while (tmp)
	{
		i = tmp->binary_index;
		if (i == 0)
			len = 1;
		else
			len = ft_loop_len_binary(tmp);
		tmp->len_binary = len;
		len = 0;
		tmp = tmp->next;
	}
}

// Send the greatest sized binary (number of figures)
int	ft_greatest_len_binary(t_list **a)
{
	int		greatest;
	t_list	*tmp;

	greatest = 0;
	if (a == NULL)
		return (0);
	tmp = *a;
	ft_len_binary(a);
	if (tmp)
		greatest = tmp->len_binary;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp && greatest < tmp->len_binary)
			greatest = tmp->len_binary;
	}
	return (greatest);
}

int	ft_push_bits_zero_to_b(t_list **a, t_list **b)
{
	int		greatest_binary;
	int		pos;
	int		count;

	if (a == NULL)
		return (-1);
	count = 0;
	pos = (*a)->position;
	greatest_binary = ft_greatest_len_binary(a);
	while (greatest_binary > 0)
	{
		pos = (*a)->position;
		count += ft_loop_push_to_b(a, b, pos);
		while (*b)
		{
			pa(a, b);
			count++;
		}
		greatest_binary--;
	}
	return (count);
}
