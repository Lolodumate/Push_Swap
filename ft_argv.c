/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:31:58 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 19:47:50 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_argv_compliant(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = 0;
	while (argv[j])
	{
		while (ft_isdigit_or_issign(argv[j][i]) || argv[j][i] == ' ')
		{
			if (argv[j][i] == '-' || argv[j][i] == '+')
				if (!argv[j][i + 1] || argv[j][i + 1] == '-' ||
					argv[j][i + 1] == '+' || argv[j][i + 1] == ' ')
					return (0);
			i++;
			len++;
		}
		j = ft_loop_argv_compliant(argv, i, j);
		if (j < 0)
			return (0);
		i = 0;
	}
	return (len);
}

int	ft_len_argv(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = 0;
	while (argv[j])
	{
		while (argv[j][i])
		{
			len++;
			i++;
		}
		i = 0;
		j++;
		if (argv[j])
			len++;
	}
	return (len);
}
