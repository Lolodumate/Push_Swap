/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:30:04 by laroges           #+#    #+#             */
/*   Updated: 2023/09/29 08:40:01 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_list
{
	int			value;
	int			smallest_value_indicator;
	int			greatest_value_indicator;
	int			len_binary;
	int			position;
	int			index;
	int			index_tmp;
	int			count;
	int			binary_index;
	char		name_stack;
	struct	s_list	*next;
}		t_list;

char				*ft_strcpy(char *str1, char *str2, int j);
char				*ft_fill_value(char *str, char *value, int i, int len);
int			ft_argv_compliant(char *str);
int			ft_isdigit(char c);
int			ft_is_greater_than(t_list **lst);
int			ft_limits(long long value);
//int			ft_place_index(char *str, int i);
int			ft_atoi(char *str);
int			ft_strchr(char *str, char c);
int			ft_check_list(t_list **lst);
int			ft_convert_int(char *str, int i);
int			ft_sort(t_list **a, t_list **b);
int			ft_strlen(char *str);
void			ft_fill_index(t_list **a);
int			ft_greatest_len_binary(t_list **a);
int			ft_convert_binary(int index); // utils.c - Trop de lignes.
t_list			*ft_smallest_value(t_list **lst); // ft_sort.c - Trop de lignes.
t_list			*ft_greatest_value(t_list **lst);
t_list			*ft_pa(t_list **a, t_list **b);
//void		ft_swap(t_list **lst);
void		ft_exit(t_list **a, t_list **b);
void		ft_free(t_list **a, t_list **b);
void		ft_len_binary(t_list **a);
void		ft_print_stack(t_list **lst);
void		ft_putstr(char *str);
int		ft_do_swap(t_list **a, t_list **b);
int		ft_sort_small_stack(t_list **a, t_list **b);
void		ft_sort_big_stack(t_list **b);
int		ft_push_bits_zero_to_b(t_list **a, t_list **b); // ft_radix.c - Trop de lignes.
int		ft_len_number(char *str, int i);
void		sa(t_list **a); // Swap les deux premiers. Test OK
void		sb(t_list **b); // Swap les deux premiers. Test OK
void		ss(t_list **a, t_list **b);
void		ra(t_list **a); // Le premier devient le dernier. Test OK
void		rb(t_list **b); // Le premier devient le dernier. Test OK
void		rr(t_list **a, t_list **b);
void		rra(t_list **a); // Le dernier devient le premier. Test OK
void		rrb(t_list **b); // Le dernier devient le premier. Test OK
void		rrr(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b); // Le premier de b va sur le sommet de a. Test OK
void		pb(t_list **a, t_list **b); // Le premier de a va sur le sommet de b. Test OK

t_list	*ft_lstnew(void *content); // Retourne un nouveau noeud qui contient la valeur 'content'. 'next' est egal a NULL.

/*void		ft_update_position(t_list *a, t_list *b);
*/

// Fonctions de la libft
void	ft_lstadd_front(t_list **lst, t_list *new); // Ajoute le noeud 'new' au debut de la liste.
int	ft_lstsize(t_list *lst); // Compte le nombre de noeuds dans une liste.
t_list	*ft_lstlast(t_list *lst); // Retourne le dernier noeud de la liste.
void	ft_lstadd_back(t_list **lst, t_list *new); // Ajoute le noeud 'new' a la fin de la liste.
void	ft_lstdelone(t_list *lst, void (*del)(void *)); // Prend un noeud en parametre et libere la memoire du contenu du noeud en utilisant la fonction 'del' et libere le noeud. La memoire de 'next' ne doit pas etre liberee.
void	ft_lstclear(t_list **lst, void (*del)(void *)); // Supprime et libere le noeud donne en parametre et tous les suivants en utilisant les fonctions 'del' et 'free'. Le pointeur de la liste doit etre parametre a NULL.
void	ft_lstiter(t_list *lst, void (*f)(void *)); // Itere la liste 'lst' et applique la fonction 'f' au contenu de chaque noeud.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); // Itere la liste 'lst' et applique la fonction 'f' au contenu de chaque noeud. Cree une nouvelle liste qui resulte des applications successives de la fonction 'f'. La fonction 'del' est utilisee pour supprimer le contenu du noeud si necessaire.

t_list		*ft_convert_argv(t_list **a, char *str);
t_list		*ft_create_node(t_list **a, char *value, int position);
t_list		*ft_add_node(t_list *e, int e_value, int position);
t_list		*ft_free_stack(t_list *lst);
t_list		*ft_check_duplicate(int	value, t_list *a);
t_list		*ft_duplicate(t_list *a);

#endif
