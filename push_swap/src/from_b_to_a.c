/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:57:37 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:52 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	conditions_four(t_stack *a, t_stack *b, int indexa, int indexb)
{
	indexb = calc_cost(b, indexb);
	indexa = calc_cost(a, indexa);
	while (indexb > 0)
	{
		rotate_reverse_b(b);
		indexb--;
	}
	while (indexa > 0)
	{
		rotate_a(a);
		indexa--;
	}
	push_a(a, b);
}

static void	conditions_three(t_stack *a, t_stack *b, int indexa, int indexb)
{
	indexb = calc_cost(b, indexb);
	indexa = calc_cost(a, indexa);
	while (indexb > 0)
	{
		rotate_b(b);
		indexb--;
	}
	while (indexa > 0)
	{
		rotate_reverse_a(a);
		indexa--;
	}
	push_a(a, b);
}

static void	conditions_two(t_stack *a, t_stack *b, int indexa, int indexb)
{
	indexa = calc_cost(a, indexa);
	indexb = calc_cost(b, indexb);
	while (indexa > 0 || indexb > 0)
	{
		if (indexa > 0 && indexb == 0)
		{
			rotate_a(a);
			indexa--;
		}
		else if (indexa == 0 && indexb > 0)
		{
			rotate_b(b);
			indexb--;
		}
		else if (indexa > 0 && indexb > 0)
		{
			double_rotate(a, b);
			indexa--;
			indexb--;
		}
	}
	push_a(a, b);
}

static void	conditions_one(t_stack *a, t_stack *b, int indexa, int indexb)
{
	indexb = calc_cost(b, indexb);
	indexa = calc_cost(a, indexa);
	while (indexa > 0 || indexb > 0)
	{
		if (indexa > 0 && indexb == 0)
		{
			rotate_reverse_a(a);
			indexa--;
		}
		else if (indexa == 0 && indexb > 0)
		{
			rotate_reverse_b(b);
			indexb--;
		}
		else if (indexa > 0 && indexb > 0)
		{
			double_reverse_rotate(a, b);
			indexa--;
			indexb--;
		}
	}
	push_a(a, b);
}

void	from_b_to_a(t_stack *a, t_stack *b)
{
	int	indexa;
	int	indexb;
	int	rotatea;
	int	rotateb;

	while (b->size > 0)
	{
		find_solution(a, b, &indexa, &indexb);
		rotatea = rotate_direction(a, indexa);
		rotateb = rotate_direction(b, indexb);
		if (rotatea == -1 && rotateb == -1)
			conditions_one(a, b, indexa, indexb);
		else if (rotatea >= 0 && rotateb >= 0)
			conditions_two(a, b, indexa, indexb);
		else if (rotatea == -1 && rotateb >= 0)
			conditions_three(a, b, indexa, indexb);
		else if (rotatea >= 0 && rotateb == -1)
			conditions_four(a, b, indexa, indexb);
	}
}
