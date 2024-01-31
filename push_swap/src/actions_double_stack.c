/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_double_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:41:17 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/26 13:41:21 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	ft_printf("%s\n", "rrr");
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	ft_printf("%s\n", "rr");
}

void	swap_double(t_stack *a, t_stack *b)
{
	swap_elem(a);
	swap_elem(b);
	ft_printf("%s\n", "ss");
}
