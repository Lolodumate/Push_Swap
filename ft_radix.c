#include "push_swap.h"

// ra : le premier devient le dernier.
// pb : le premier de a devient le premier de b.

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
			while (i > 0)
			{
				i /= 10;
				len++;
			}
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

int	ft_push_zero(t_list **a, t_list **b)
{
	int		greatest_binary;
	int		tmp;
	int		pos;
	int		count;
	t_list	*tmp_a;

	if (a == NULL)
		return (-1);
	tmp = 0;
	count = 0;
	tmp_a = *a;
	pos = tmp_a->position;
	greatest_binary = ft_greatest_len_binary(a);
	while (greatest_binary > 0)
	{
		printf("greatest_binary = %d\n", greatest_binary);
		pos = (*a)->position;
		while (*a && pos-- > 0) // tmp_a == *a
		{
			tmp = (*a)->index_tmp % 2; // (*a)->index_tmp % 2
			(*a)->index_tmp /= 10; // (*a)->index_tmp /= 10
			if (tmp == 0)
				pb(a, b);
			else
				ra(a);
			count++;
			tmp_a = *a;
			if (tmp_a)
			{
				ft_print_stack(a);
				ft_print_stack(b);
			}
			printf("*****************************************************************\n");
		}
		ft_print_stack(a);
		ft_print_stack(b);
		while (*b)
		{
			pa(a, b);
			count++;
//			printf("Position A = %d - Position B = %d\n", (*a)->position, (*b)->position);
			ft_print_stack(a);
			ft_print_stack(b);
			printf("*****************************************************************\n");
		}
		greatest_binary--;
	}
	return (count);
}
