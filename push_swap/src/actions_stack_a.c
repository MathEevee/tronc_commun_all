/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:39:11 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:34:48 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_reverse_a(t_stack *a)
{
	rotate_down(a);
	ft_printf("%s\n", "rra");
}

void	rotate_a(t_stack *a)
{
	rotate_up(a);
	ft_printf("%s\n", "ra");
}

void	push_a(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("%s\n", "pa");
}

void	swap_a(t_stack *a)
{
	swap_elem(a);
	ft_printf("%s\n", "sa");
}
