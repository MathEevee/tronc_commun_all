/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:09:40 by matde-ol          #+#    #+#             */
/*   Updated: 2023/11/20 18:11:20 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_bis(char *src)
{
	int	i;

	if (src != NULL)
	{
		i = 0;
		while (src[i] != '\0')
		{
			if (src[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	free(s2);
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *src, int start, int len)
{
	char	*dest;
	int		i;

	if (src == NULL)
		return (NULL);
	i = 0;
	if (len >= ft_strlen(src + start))
		len = ft_strlen(src + start);
	if (len == 0 || start >= ft_strlen(src))
	{
		dest = malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i + start < len || src[start + i] != '\0')
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strlcpy_f(char *src, int len)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}
