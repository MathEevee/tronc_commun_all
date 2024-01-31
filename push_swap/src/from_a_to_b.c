/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:42:35 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/22 22:03:51 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_quart_low(t_stack *stack)
{
	int	quart_low;
	int	i;
	int	nb;
	int	min;

	i = 0;
	nb = 0;
	min = search_min(stack);
	while (nb < stack->size / 4)
	{
		i = 0;
		quart_low = INT_MAX;
		while (i < stack->size)
		{
			if (stack->value[i] < quart_low && stack->value[i] > min)
				quart_low = stack->value[i];
			i++;
		}
		min = quart_low;
		nb++;
	}
	return (quart_low);
}

void	from_a_to_b(t_stack *a, t_stack *b)
{
	int	quart_low;
	int	mediane;
	int	size;

	quart_low = search_quart_low(a);
	mediane = search_mediane(a);
	size = (a->size / 4);
	while (size > 0 && a->size > 3)
	{
		if (a->value[a->size - 1] > mediane)
		{
			if (b->value[b->size - 1] < quart_low && b->size > 3)
				rotate_reverse_b(b);
			push_b(a, b);
			size--;
		}
		else
		{
			if (b->value[b->size - 1] < quart_low && b->size > 3)
				double_rotate(a, b);
			else
				rotate_a(a);
		}
	}
}
