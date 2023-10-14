/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:04 by laroges           #+#    #+#             */
/*   Updated: 2023/10/14 22:17:45 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list_ps
{
	int					value;
	int					smallest_value_indicator;
	int					greatest_value_indicator;
	int					len_binary;
	int					position;
	int					index;
	int					index_tmp;
	int					count;
	int					binary_index;
	int					lock;
	char				name_stack;
	struct s_list_ps	*next;
}	t_list_ps;

int			ft_argv_compliant(char **argv);
int			ft_len_argv(char **argv);
int			ft_loop_argv_compliant(char **argv, int i, int j);
int			ft_loop_len_binary(t_list_ps *lst);
int			ft_loop_push_to_b(t_list_ps **a, t_list_ps **b, int position);
int			ft_is_greater_than(t_list_ps **lst);
int			ft_limits(long value);
int			ft_lstsize(t_list_ps *lst);
int			ft_check_list(t_list_ps **lst);
int			ft_convert_int(char *str, int i);
int			ft_sort(t_list_ps **a, t_list_ps **b);
int			ft_greatest_len_binary(t_list_ps **a);
int			ft_convert_binary(int index);
int			ft_push_bits_zero_to_b(t_list_ps **a, t_list_ps **b);
int			ft_len_number(char *str, int i);
char		*ft_bits_convert_binary(int index, char *res, char bits[64]);
char		*ft_build_str(int argc, char **argv);
char		*ft_create_str(char **argv, int len);
char		*ft_create_strjoin(char **argv, int len);
char		*ft_create_value(char *str, int i, int len);
char		*ft_strcpy(char *str1, char *str2, int j);
char		*ft_fill_value(char *str, char *value, int i, int len);
void		ft_exit(t_list_ps **a, t_list_ps **b);
void		ft_fill_index(t_list_ps **a);
void		ft_free(t_list_ps **a, t_list_ps **b);
void		ft_len_binary(t_list_ps **a);
void		ft_sort_small_stack(t_list_ps **a, t_list_ps **b);
void		ft_stack_sized_two(t_list_ps **a);
void		ft_stack_sized_three(t_list_ps **a);
void		ft_stack_sized_four(t_list_ps **a, t_list_ps **b);
void		ft_stack_sized_five(t_list_ps **a, t_list_ps **b);
void		sa(t_list_ps **a);
void		sb(t_list_ps **b);
void		ss(t_list_ps **a, t_list_ps **b);
void		ra(t_list_ps **a);
void		rb(t_list_ps **b);
void		rr(t_list_ps **a, t_list_ps **b);
void		rra(t_list_ps **a);
void		rrb(t_list_ps **b);
void		rrr(t_list_ps **a, t_list_ps **b);
void		pa(t_list_ps **a, t_list_ps **b);
void		pb(t_list_ps **a, t_list_ps **b);
void		ft_update_index(t_list_ps **a, t_list_ps **b);
t_list_ps	*ft_init_stack(int argc, char **argv, t_list_ps **a, t_list_ps **b);
t_list_ps	*ft_loop_smallest_ptr(t_list_ps **lst);
t_list_ps	*ft_lstlast(t_list_ps *lst);
t_list_ps	*ft_find_smallest_value(t_list_ps **lst, t_list_ps *t_small, int s);
t_list_ps	*ft_build_stack(t_list_ps **a, t_list_ps **b, char *str);
t_list_ps	*ft_create_node(t_list_ps **a, char *value, int position);
t_list_ps	*ft_add_node(t_list_ps *e, int e_value, int position);
t_list_ps	*ft_free_stack(t_list_ps *lst);
t_list_ps	*ft_check_duplicate(int value, t_list_ps *a);
t_list_ps	*ft_duplicate(t_list_ps **a);
t_list_ps	*ft_smallest_value(t_list_ps **lst);
t_list_ps	*ft_smallest_value_indicator(t_list_ps **a);
t_list_ps	*ft_greatest_value(t_list_ps **lst);

#endif
