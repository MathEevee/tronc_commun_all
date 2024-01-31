/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:05:05 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/19 14:12:42 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*check_white_space(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] >= 9 && src[i] <= 13)
			src[i] = ' ';
		i++;
	}
	return (src);
}

static void	low_numbers_presort(t_stack *a, t_stack *b)
{
	if (a->size < 10)
	{
		while (a->size != 3)
			push_b(a, b);
	}
}

static t_elem	*nbr_elem(int ac, char **av)
{
	int			j;
	char		**dest;
	t_elem		*nbr;

	j = 1;
	nbr = NULL;
	while (j < ac)
	{
		av[j] = check_white_space(av[j]);
		dest = ft_split(av[j], ' ');
		create_elem_bis(dest, &nbr);
		j++;
	}
	return (nbr);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_elem	*lst;

	if (check(ac, av) == -1)
		return (msg_error());
	lst = nbr_elem(ac, av);
	a = init_stack_a(lst);
	if (input_sort(a) == -1)
		return (0);
	b = init_stack_b(a);
	if (b->size < 1 && a->size > 3)
		push_b(a, b);
	low_numbers_presort(a, b);
	while (a->size > 3)
		from_a_to_b(a, b);
	sort_a(a);
	from_b_to_a(a, b);
	rotate_stack_a(a);
	free_stack(a, b);
	return (0);
}
