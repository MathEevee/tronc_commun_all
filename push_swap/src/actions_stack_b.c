/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:39:43 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:40:05 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_b(t_stack *b)
{
	rotate_down(b);
	ft_printf("%s\n", "rrb");
}

void	rotate_b(t_stack *b)
{
	rotate_up(b);
	ft_printf("%s\n", "rb");
}

void	push_b(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("%s\n", "pb");
}

void	swap_b(t_stack *b)
{
	swap_elem(b);
	ft_printf("%s\n", "sb");
}
