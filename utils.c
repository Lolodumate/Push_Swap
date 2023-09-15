/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:41:53 by laroges           #+#    #+#             */
/*   Updated: 2023/09/15 15:29:03 by laroges          ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
