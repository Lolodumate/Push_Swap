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

int	ft_push_bits_zero_to_b(t_list **a, t_list **b)
{
	int		greatest_binary;
	int		tmp;
	int		pos;
	int		count;
//	int		i;

	if (a == NULL)
		return (-1);
	tmp = 0;
	count = 0;
	pos = (*a)->position;
//	i = (*a)->position;
	greatest_binary = ft_greatest_len_binary(a);
	while (greatest_binary > 0)
	{
		pos = (*a)->position;
		while (*a && pos-- > 0)
		{
			tmp = (*a)->index_tmp % 2;
			(*a)->index_tmp /= 10;
			// Cette section permet d'identifer le plus grand nombre et de le placer en bas de la pile B pour le mettre en attente. Ainsi, Radix aura moins de traitements à faire.
			// Elle permet de diminier le nombre de coups de quelques dizaines sur une liste de 100 nombres.
/*			if ((*a)->index == i)
			{
				(*a)->lock = 1;
				pb(a, b);
				count++;
				rb(b);
				i--;
			}
			else*/ if (tmp == 0)
				pb(a, b);
			else
				ra(a);
			count++;
		}
		ft_print_stack(a);
		ft_print_stack(b);
		while (*b/* && (*b)->lock != 1*/)
		{
			pa(a, b);
			count++;
		}
		greatest_binary--;
		if (greatest_binary == 0)
		{
			if (*b)
				pos = (*b)->position;
			while (*b)
			{
				pa(a, b);
				count++;
			}
/*			while (pos-- > 0)
			{
				ra(a);
				count++;
			}
*/		}
	}
	return (count);
}

// Fonction a revoir : le but est de placer les plus grandes valeurs dans la moitie haute de la pile A.

/*
int	ft_presort(t_list **a, t_list **b)
{
	int		pos;
	int		median;
	int		count;

	pos = (*a)->position;
	median = pos / 2;
	count = 0;
	printf("Valeur de median = %d\n", median);
	while (pos-- > 0)
	{
		
		if ((*a)->index < median)
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->index == greatest_index)
			{
				(*b)->lock = 1;
				rb(b);
				count++;
				greatest_index--;
			}
		}
		count++;
		
		printf("Valeur de pos = %d\n", pos);
		printf("Valeur de tmp->index = %d\n", (*a)->index);
	//	ft_print_stack(b);
	}
	while (*b && (*b)->lock != 1)
	{
		pa(a, b);
		count++;
	}
	printf("Affichage piles après ft_presort\n");
	ft_print_stack(a);
	ft_print_stack(b);
	return (count);
}
*/
