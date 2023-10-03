/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:53 by laroges           #+#    #+#             */
/*   Updated: 2023/09/28 23:32:03 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (!c)
		return (0);
	if (ft_strchr("0123456789+-",c))
		return (1);
	return (0);
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
	int		i;
	int		j;
	int		bits_int;
	char	bits[8];
	char	*res;

	i = 0;
	j = 0;
	bits_int = 0;
	res = malloc(sizeof(char) * 8 + 1);
	if (res == NULL)
		return (-1);
	res[8] = '\0';
	while (i < 8)
	{
		bits[i] = (index % 2) + '0';
		index /= 2;
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		res[j] = bits[i];
		j++;
		i--;
	}
	bits_int = ft_atoi(res);
	free(res);
	return (bits_int);
}
