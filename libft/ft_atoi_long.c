/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:47:26 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 17:53:50 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long(char *value)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (value[i] == '-' || value[i] == '+')
	{
		if (value[i] == '-')
			sign *= -1;
		i++;
	}
	while (value[i] >= '0' && value[i] <= '9')
	{
		res = (res * 10) + (value[i] - '0');
		i++;
	}
	return (res * sign);
}
