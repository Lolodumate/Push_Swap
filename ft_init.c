/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:13:52 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 18:38:45 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculation of the lenght for ft_convert_argv
int	ft_len_number(char *str, int i)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[i] && !ft_isdigit_or_issign(str[i]))
		i--;
	while (i >= 0 && str[i] && ft_isdigit_or_issign(str[i]))
	{
		len++;
		i--;
	}
	return (len);
}

// Filling of the (*a)->value for ft_convert_argv
char	*ft_fill_value(char *str, char *value, int i, int len)
{
	if (!str || !value || len == 0)
		return (NULL);
	len--;
	while (len >= 0 && i >= 0)
	{
		value[len] = str[i];
		i--;
		len--;
	}
	return (value);
}

t_list_ps	*ft_create_node(t_list_ps **a, char *value, int position)
{
	if (!a || !value)
		return (NULL);
	if (!ft_limits(ft_atoi_long(value)))
		return (NULL);
	*a = ft_add_node(*a, (int)ft_atoi_long(value), position);
	(*a)->name_stack = 'A';
	free(value);
	return (*a);
}

// Check of the integer limits for ft_convert_argv
int	ft_limits(long value)
{
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}

t_list_ps	*ft_duplicate(t_list_ps **a)
{
	t_list_ps	*tmp;

	tmp = *a;
	if (*a == NULL)
		return (NULL);
	while (tmp)
	{
		if (ft_check_duplicate(tmp->value, tmp) != NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (*a);
}
