/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:57:53 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/02 11:44:16 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(t_stack *s, int idx)
{
	int	cost;

	if (idx < s->size / 2)
		cost = idx + 1;
	else
		cost = s->size - 1 - idx;
	return (cost);
}
