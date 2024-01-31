/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:07:02 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:32:28 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_stack *a)
{
	int	min;
	int	idx_min;

	min = search_min(a);
	idx_min = search_min_pos(a, min);
	if (idx_min < a->size / 2)
	{
		while (a->value[a->size - 1] != min)
			rotate_reverse_a(a);
	}
	else
	{
		while (a->value[a->size - 1] != min)
			rotate_a(a);
	}
}
