/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:16:04 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/02 11:50:21 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack->value[0];
	while (i < stack->size)
	{
		if (max < stack->value[i])
			max = stack->value[i];
		i++;
	}
	return (max);
}

int	search_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->value[0];
	while (i < stack->size)
	{
		if (min > stack->value[i])
			min = stack->value[i];
		i++;
	}
	return (min);
}

int	search_mediane(t_stack *stack)
{
	int	mediane;
	int	i;
	int	nb;
	int	max;

	i = 0;
	nb = 0;
	max = search_max(stack);
	while (nb < stack->size / 2)
	{
		i = 0;
		mediane = INT_MIN;
		while (i < stack->size)
		{
			if (stack->value[i] > mediane && stack->value[i] < max)
				mediane = stack->value[i];
			i++;
		}
		max = mediane;
		nb++;
	}
	return (mediane);
}

int	search_min_pos(t_stack *stack, int min)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		if (stack->value[i] == min)
			return (i);
		i--;
	}
	return (i);
}
