/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:53 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 14:45:38 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_list **a, t_list **b)
{
	ft_free(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_list **a, t_list **b)
{
	if (*a)
		ft_free_stack(*a);
	if (*b)
		ft_free_stack(*b);
	free(a);
	free(b);
}

char	*ft_strcpy(char *str1, char *str2, int j)
{
	int	i;

	i = 0;
	while (ft_isdigit(str2[i]))
	{
		str1[i] = str2[i + j];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

int	ft_convert_int(char *str, int i)
{
	int		len;
	int		value;
	char	*s;

	len = 0;
	value = 0;
	while (ft_isdigit(str[len + i]))
		len++;
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (-1);
	ft_strcpy(s, str, i);
	value = ft_atoi(s);
	free(s);
	return (value);
}

// Convertir les index en binaire
int	ft_convert_binary(int index)
{
	int		bits_int;
	char	bits[64];
	char	*res;

	bits_int = 0;
	bits[0] = '\0';
	res = malloc(sizeof(char) * 64 + 1);
	if (res == NULL)
		return (-1);
	res[64] = '\0';
	res = ft_bits_convert_binary(index, res, bits);
	bits_int = ft_atoi(res);
	free(res);
	return (bits_int);
}
