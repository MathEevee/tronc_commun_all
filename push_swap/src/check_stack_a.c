/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:28:36 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:23:37 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_sort(t_stack *a)
{
	int	i;

	i = 0;
	if (a->size == 2)
	{
		if (a->value[0] < a->value[1])
		{
			swap_a(a);
			free(a->value);
			free(a);
			return (-1);
		}
		free(a->value);
		free(a);
		return (-1);
	}
	while (i < a->size - 1)
	{
		if (a->value[i] < a->value[i + 1])
			return (0);
		i++;
	}
	free(a->value);
	free(a);
	return (-1);
}
