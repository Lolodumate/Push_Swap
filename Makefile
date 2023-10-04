FLAGS = -Wall -Werror -Wextra -g

m:
	@gcc $(FLAGS) push_swap.c ft_stack.c utils.c ft_swap.c ft_rotate.c libft.c ft_reverse_rotate.c ft_push.c ft_sort.c ft_radix.c -o ./push_swap
