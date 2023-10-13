/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:24:31 by laroges           #+#    #+#             */
/*   Updated: 2023/10/10 15:56:49 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

int	ft_isdigit(char c)
{
	if (!c)
		return (0);
	if (ft_strchr("0123456789+-", (int)c))
		return (1);
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	ft_lstsize(t_list *lst)
{
	size_t	nb_elt;

	nb_elt = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		nb_elt++;
	}
	return (nb_elt);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (nmemb != 0 && size != 0 && ((nmemb * size) / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset((unsigned char *)ptr, 0, nmemb * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char *)s + n - 1) = (unsigned char)c;
		n--;
	}
	return (s);
}

long	ft_atoi(char *value)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (value[i] == '-' || value[i] == '+')
	{
		if (value[i] == '-')
			sign *= -1;
		i++;
	}
	while (value[i] >= '0' && value[i] <= '9')
	{
		res = (res * 10) + (value[i] - '0');
		i++;
	}
	return (res * sign);
}
