#include "push_swap.h"

static void	ft_print_stack(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		printf("\nft_stack.c l.73 A EFFACER : La pile est vide.\n\n");
		return ;
	}
	while (tmp)
	{
		printf("#%3d - Pile[%c] - I [%3d] - I_Bits %12d - I_tmp %8d - Small %d - Value [%d]\n", tmp->position, tmp->name_stack, tmp->index, tmp->binary_index, tmp->index_tmp, tmp->smallest_value_indicator, tmp->value);
		tmp = tmp->next;
		if (tmp == NULL)
			printf("ft_stack.c l.82 A EFFACER : Fin de la pile.\n\n");
	}
}
