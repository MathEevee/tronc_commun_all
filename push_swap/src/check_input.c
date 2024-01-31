/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:56:47 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/31 13:53:22 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	invalid_nbr(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (((!(src[i] >= '0' && src[i] <= '9'))
				&& (src[i] != ' ' && src[i] != '+' && src[i] != '-'))
			&& (!(src[i] >= 9 && src[i] <= 13)))
			return (-1);
		if (src[i] == '-' && (!(src[i + 1] >= '0' && src[i + 1] <= '9'
					&& (i == 0 || src[i - 1] == ' '
						|| (src[i - 1] >= 9 && src[i - 1] <= 13)))))
			return (-1);
		if (src[i] == '+' && (!(src[i + 1] >= '0' && src[i + 1] <= '9'
					&& (i == 0 || src[i - 1] == ' '
						|| (src[i - 1] >= 9 && src[i - 1] <= 13)))))
			return (-1);
		i++;
	}
	return (0);
}

int	check(int ac, char **av)
{
	int	j;

	j = 1;
	while (j < ac)
	{
		if (invalid_nbr(av[j]) == -1)
			return (-1);
		j++;
	}
	return (0);
}

int	double_nbr_check(t_elem *nbr, int elem)
{
	while (nbr != NULL)
	{
		if (elem == nbr->value)
			return (-1);
		nbr = nbr->next;
	}
	return (0);
}

int	msg_error(void)
{
	write (2, "Error\n", 6);
	return (0);
}
