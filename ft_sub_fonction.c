/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_fonction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:06:10 by laroges           #+#    #+#             */
/*   Updated: 2023/10/10 17:58:54 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sub fonction for ft_build_stack
char	*ft_create_value(char *str, int i, int len)
{
	char	*tmp;

	tmp = ft_calloc(sizeof(char), len + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_fill_value(str, tmp, i, len);
	if (tmp == NULL)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

// Sub fonction for ft_len_binary
int	ft_loop_len_binary(t_list *lst)
{
	int	len;
	int	i;

	len = 0;
	i = lst->binary_index;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

// Sub fonction for ft_push_bits_zero_to_b
int	ft_loop_push_to_b(t_list **a, t_list **b, int position)
{
	int	tmp;
	int	count;

	tmp = 0;
	count = 0;
	while (*a && position-- > 0)
	{
		tmp = (*a)->index_tmp % 2;
		(*a)->index_tmp /= 10;
		if (tmp == 0)
			pb(a, b);
		else
			ra(a);
		count++;
	}
	return (count);
}

// Sub fonction for ft_argv_compliant
int	ft_loop_argv_compliant(char **argv, int i, int j)
{
	if (argv[j][i] == '\0')
		j++;
	else
		return (0);
	return (j);
}

// Sub fonction for ft_convert_binary
char	*ft_bits_convert_binary(int index, char *res, char bits[64])
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i++ < 64)
	{
		bits[i] = (index % 2) + '0';
		index /= 2;
	}
	i = 63;
	while (i-- >= 0)
	{
		res[j] = bits[i];
		j++;
	}
	return (res);
}
