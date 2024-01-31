/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:05:56 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/31 10:41:18 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_idx_a(t_stack *a, int value_b, int idx_a)
{
	int	value_a;
	int	idx;
	int	left;

	left = a->size;
	idx = search_min_pos(a, search_min(a));
	if (value_b > search_max(a))
		return (idx);
	while (left > 0)
	{
		value_a = a->value[idx];
		if (value_b < value_a)
		{
			idx_a = idx;
			return (idx_a);
		}
		idx--;
		if (idx < 0)
			idx = a->size - 1;
		left--;
	}
	return (0);
}

void	find_solution(t_stack *a, t_stack *b, int *best_idx_a, int *best_idx_b)
{
	int	best_cost;
	int	cost;
	int	idx_a;
	int	idx_b;
	int	value_b;

	best_cost = INT_MAX;
	idx_b = b->size - 1;
	while (idx_b >= 0)
	{
		value_b = b->value[idx_b];
		idx_a = calc_idx_a(a, value_b, idx_a);
		cost = calc_cost(a, idx_a) + calc_cost(b, idx_b);
		if (cost < best_cost)
		{
			*best_idx_b = idx_b;
			*best_idx_a = idx_a;
			best_cost = cost;
		}
		idx_b--;
	}
}
