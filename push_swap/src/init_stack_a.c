/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:36:03 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/31 13:32:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	lstsize_elem(t_elem *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

static t_elem	*lstlast_elem(t_elem *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	lst_del_last(t_elem *lst)
{
	t_elem	*tmp;

	if (lst == NULL)
		return ;
	if (lst->next == NULL)
	{
		free(lst);
		return ;
	}
	while (lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
	}
	free(lst);
	tmp->next = NULL;
}

t_stack	*init_stack_a(t_elem *elem)
{
	t_stack	*stack_a;
	int		i;
	t_elem	*tmp;

	stack_a = malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (NULL);
	stack_a->size = lstsize_elem(elem);
	i = 0;
	stack_a->value = malloc(stack_a->size * sizeof(int));
	if (stack_a->value == NULL)
	{
		free(stack_a);
		return (NULL);
	}
	while (i < stack_a->size)
	{
		tmp = lstlast_elem(elem);
		stack_a->value[i] = tmp->value;
		lst_del_last(elem);
		i++;
	}
	return (stack_a);
}
