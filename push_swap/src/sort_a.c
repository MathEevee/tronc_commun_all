/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:33:08 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/22 15:47:14 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *a)
{
	if (!(a->value[2] < a->value[1] && a->value[1] < a->value[0]
			&& a->value[2] < a->value[0]))
	{
		if (search_max(a) == a->value[1])
			rotate_reverse_a(a);
		else if (search_max(a) == a->value[2])
			rotate_a(a);
		else if (a->value[2] > a->value[1])
			swap_a(a);
		sort_a(a);
	}
	else
		return ;
}
