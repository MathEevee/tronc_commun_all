/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:03:28 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/18 13:55:02 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishexa(char c)
{
	if (ft_isdigit(c) == 1 || (c >= 'A' && c <= 'F')
		|| (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}
