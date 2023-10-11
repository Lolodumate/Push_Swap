/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:04 by laroges           #+#    #+#             */
/*   Updated: 2023/10/11 20:28:24 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				smallest_value_indicator;
	int				greatest_value_indicator;
	int				len_binary;
	int				position;
	int				index;
	int				index_tmp;
	int				count;
	int				binary_index;
	int				lock;
	char			name_stack;
	struct s_list	*next;
}	t_list;

int				ft_argv_compliant(char **argv);
int				ft_len_argv(char **argv);
int				ft_loop_argv_compliant(char **argv, int i, int j);
int				ft_loop_len_binary(t_list *lst);
int				ft_loop_push_to_b(t_list **a, t_list **b, int position);
int				ft_lstsize(t_list *lst);
int				ft_isdigit(char c);
int				ft_is_greater_than(t_list **lst);
int				ft_limits(long value);
int				ft_strchr(char *str, char c);
int				ft_check_list(t_list **lst);
int				ft_convert_int(char *str, int i);
int				ft_presort(t_list **a, t_list **b);
int				ft_sort(t_list **a, t_list **b);
int				ft_sort_small_stack(t_list **a, t_list **b);
int				ft_stack_sized_two(t_list **a);
int				ft_stack_sized_three(t_list **a);
int				ft_stack_sized_four(t_list **a, t_list **b);
int				ft_stack_sized_five(t_list **a, t_list **b);
int				ft_strlen(const char *str);
int				ft_greatest_len_binary(t_list **a);
int				ft_convert_binary(int index); // utils.c - Trop de lignes.
int				ft_push_bits_zero_to_b(t_list **a, t_list **b);//ft_radix.c-Trop de lignes.
int				ft_len_number(char *str, int i);
char			*ft_bits_convert_binary(int index, char *res, char bits[64]);
char			*ft_build_str(int argc, char **argv);
char			*ft_create_str(char **argv, int len);
char			*ft_create_strjoin(char **argv, int len);
char			*ft_create_value(char *str, int i, int len);
char			*ft_strcpy(char *str1, char *str2, int j);
char			*ft_fill_value(char *str, char *value, int i, int len);
char			*ft_strjoin(char *s1, char *s2);
long			ft_atoi(char *str);
void			*ft_calloc(size_t nmemb, size_t size);
void			ft_exit(t_list **a, t_list **b);
void			ft_fill_index(t_list **a);
void			ft_free(t_list **a, t_list **b);
void			ft_len_binary(t_list **a);
void			*ft_memset(void *s, int c, size_t n);
void			ft_print_stack(t_list **lst);
void			sa(t_list **a);
void			sb(t_list **b);
void			ss(t_list **a, t_list **b);
void			ra(t_list **a);
void			rb(t_list **b);
void			rr(t_list **a, t_list **b);
void			rra(t_list **a);
void			rrb(t_list **b);
void			rrr(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_update_index(t_list **a, t_list **b);
t_list			*ft_init_stack_a(int argc, char **argv, t_list **a, t_list **b);
t_list			*ft_loop_smallest_ptr(t_list **lst);
t_list			*ft_loop_find_smallest_value(t_list **lst, t_list *t_small, int smallest);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_build_stack(t_list **a, t_list **b, char *str);
t_list			*ft_create_node(t_list **a, char *value, int position);
t_list			*ft_add_node(t_list *e, int e_value, int position);
t_list			*ft_free_stack(t_list *lst);
t_list			*ft_check_duplicate(int value, t_list *a);
t_list			*ft_duplicate(t_list *a);
t_list			*ft_smallest_value(t_list **lst);
t_list			*ft_smallest_value_indicator(t_list **a);
t_list			*ft_greatest_value(t_list **lst);

#endif
