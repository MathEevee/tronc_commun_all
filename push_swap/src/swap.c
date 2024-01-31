/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:13:27 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/23 00:37:57 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_elem(t_stack *stack)
{
	int	tmp;
	int	size;

	size = stack->size;
	tmp = stack->value[size - 1];
	stack->value[size - 1] = stack->value[size - 2];
	stack->value[size - 2] = tmp;
}
