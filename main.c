/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:44:42 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 22:06:36 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Test : make m && valgrind ./push_swap 5 3 4 6 7 8 1 2 9 0-0000000 10
int	main(int argc, char **argv)
{
	t_list_ps	**a;
	t_list_ps	**b;

	a = (t_list_ps **)malloc(sizeof(t_list_ps));
	b = (t_list_ps **)malloc(sizeof(t_list_ps));
	if (a == NULL || b == NULL)
		return (-1);
	*a = NULL;
	*b = NULL;
	if (argc > 1)
	{
		*a = ft_init_stack(argc, argv, a, b);
		if (!ft_check_list(a))
		{
			if (ft_lstsize(*a) > 5)
				ft_push_bits_zero_to_b(a, b);
			else
				ft_sort_small_stack(a, b);
		}
	}
	ft_free(a, b);
	return (0);
}
