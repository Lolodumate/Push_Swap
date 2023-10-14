/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:12:43 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 22:05:59 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_ps	*ft_init_stack(int argc, char **argv, t_list_ps **a, t_list_ps **b)
{
	char	*str;

	str = "0";
	str = ft_build_str(argc, argv);
	if (str == NULL)
		ft_exit(a, b);
	*a = ft_build_stack(a, b, str);
	ft_fill_index(a);
	free(str);
	if (*a == NULL)
	{
		ft_free(a, b);
		return (0);
	}
	if (!ft_duplicate(a))
		ft_exit(a, b);
	return (*a);
}
