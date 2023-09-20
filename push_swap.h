/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:04 by laroges           #+#    #+#             */
/*   Updated: 2023/09/20 19:44:49 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_element
{
	int	value;
	int	position;
	int	index;
	int	count;
	struct s_element	*next;
}	t_element;
char				*ft_strcpy(char *str1, char *str2, int j);
int			ft_argv_compliant(char *str);
int			ft_isdigit(char c);
int			ft_atoi(char *str);
int			ft_strchr(char *str, char c);
int			ft_convert_int(char *str, int i);
void		ft_putstr(char *str);
void		ft_swap(int *a, int *b);
void		ft_update_position(t_element *a, t_element *b);
void		rr(t_element *a, t_element *b);
void		rrr(t_element *a, t_element *b);
void		ss(t_element *a, t_element *b);

void		pa(t_element *a, t_element *b);
void		pb(t_element *a, t_element *b);

t_element	*ra(t_element *a);
t_element	*rb(t_element *b);
t_element	*rra(t_element *a);
t_element	*rrb(t_element *b);
t_element	*sa(t_element *a);
t_element	*sb(t_element *b);
t_element	*ft_convert_argv(t_element *e, char *str);
t_element	*ft_add_element(t_element *e, int e_value, int position);
t_element	*ft_free_stack(t_element *e);
t_element	*ft_free_top_stack(t_element *e);
t_element	*ft_check_duplicate(int	value, t_element *e);
t_element	*push_swap(t_element *a);

#endif
