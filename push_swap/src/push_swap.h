/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:49:33 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/02 11:44:25 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_elem
{
	int					value;
	struct s_elem		*next;
}				t_elem;

typedef struct s_stack
{
	int		*value;
	int		size;
}				t_stack;

t_stack	*init_stack_a(t_elem *elem);
t_stack	*init_stack_b(t_stack *stack_a);
void	create_elem_bis(char **dest, t_elem **nbr);

int		check(int ac, char **av);
int		double_nbr_check(t_elem *nbr, int elem);
int		input_sort(t_stack *a);
int		msg_error(void);
int		check_overflow(char *src);

void	push(t_stack *stack_send, t_stack *stack_resave);
void	rotate_down(t_stack *stack);
void	rotate_up(t_stack *stack);
void	swap_elem(t_stack *stack);

void	double_reverse_rotate(t_stack *a, t_stack *b);
void	double_rotate(t_stack *a, t_stack *b);
void	swap_double(t_stack *a, t_stack *b);

void	rotate_reverse_a(t_stack *a);
void	rotate_a(t_stack *a);
void	push_a(t_stack *a, t_stack *b);
void	swap_a(t_stack *a);

void	rotate_reverse_b(t_stack *b);
void	rotate_b(t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	swap_b(t_stack *b);

int		search_max(t_stack *stack);
int		search_mediane(t_stack *stack);
int		search_min(t_stack *stack);
int		calc_cost(t_stack *s, int idx);
int		search_min_pos(t_stack *stack, int min);

void	from_a_to_b(t_stack *a, t_stack *b);
void	sort_a(t_stack *a);

int		rotate_direction(t_stack *p, int index);
void	find_solution(t_stack *a, t_stack *b, int *best_idx_a, int *best_idx_b);
void	from_b_to_a(t_stack *a, t_stack *b);
void	rotate_stack_a(t_stack *a);

void	free_stack(t_stack *a, t_stack *b);

#endif