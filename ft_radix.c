#include "push_swap.h"

// ra : le premier devient le dernier.
// pb : le premier de a devient de le premier de b.

void	ft_push_zero(t_list **a, t_list **b)
{
	int			mod_index;
	int			pos;
	char		bits[8] = "00000000";
	t_list	*tmp_a;
	t_list	*tmp_b;

	mod_index = 0;
	tmp_a = *a;
	tmp_b = *b;
	pos = tmp_a->position;
	while (tmp_a && pos > 0)
	{
		if (tmp_a->binary_index % 2 == 0)
			pb(a, b);
		else
			ra(a);
		pos--;
	}
	tmp_a = *a;
	pos = tmp_a->position;


}
