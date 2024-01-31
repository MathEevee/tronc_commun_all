/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:54:42 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/31 13:55:04 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*create_elem(int elem)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (new == NULL)
		return (NULL);
	new->value = elem;
	new->next = NULL;
	return (new);
}

static void	lstadd_back_elem(t_elem **lst, t_elem *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else if ((*lst)->next == NULL)
		(*lst)->next = new;
	else
		lstadd_back_elem(&(*lst)->next, new);
}

static size_t	strslen(char **strs)
{
	int	i;

	i = 0;
	if (strs)
		while (strs[i])
			i++;
	return (i);
}

static void	ft_free_lst(t_elem **nbr)
{
	t_elem	*nbr_next;

	if (nbr == NULL || *nbr == NULL)
		return ;
	while (nbr != NULL && *nbr != NULL)
	{
		nbr_next = (*nbr)->next;
		free(*nbr);
		*nbr = nbr_next;
	}
}

void	create_elem_bis(char **dest, t_elem **nbr)
{
	int		i;
	t_elem	*new;

	i = 0;
	while (dest[i] != NULL)
	{
		new = create_elem(ft_atoi(dest[i]));
		if (double_nbr_check(*nbr, new->value) == -1
			|| check_overflow(dest[i]) == -1)
		{
			ft_free_lst(&new);
			ft_free_lst(nbr);
			ft_free(dest, strslen(dest));
			exit(msg_error());
		}
		lstadd_back_elem(nbr, new);
		i++;
	}
	ft_free(dest, strslen(dest));
}
