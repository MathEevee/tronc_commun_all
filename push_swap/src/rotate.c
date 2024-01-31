/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:12:15 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/22 15:47:14 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_down(t_stack *stack)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = stack->size;
	tmp = stack->value[0];
	while (i < size - 1)
	{
		stack->value[i] = stack->value[i + 1];
		i++;
	}
	stack->value[size - 1] = tmp;
}

void	rotate_up(t_stack *stack)
{
	int	i;
	int	tmp;
	int	size;

	i = stack->size - 1;
	size = stack->size;
	tmp = stack->value[size - 1];
	while (i > 0)
	{
		stack->value[i] = stack->value[i - 1];
		i--;
	}
	stack->value[0] = tmp;
}
