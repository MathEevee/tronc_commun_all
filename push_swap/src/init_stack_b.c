/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:07:05 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:33:33 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_b(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = malloc(sizeof(t_stack));
	if (stack_b == NULL)
		return (NULL);
	stack_b->size = 0;
	i = stack_a->size;
	stack_b->value = malloc(i * sizeof(int));
	if (stack_b->value == NULL)
	{
		free(stack_b);
		return (NULL);
	}
	return (stack_b);
}
