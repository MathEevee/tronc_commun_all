/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:49:22 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/26 16:19:10 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t nb)
{
	size_t	i;

	i = 0;
	while (i < nb && str1[i] && str1[i] == str2[i])
		i++;
	if (i == nb)
		return (0);
	return (*(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i));
}
