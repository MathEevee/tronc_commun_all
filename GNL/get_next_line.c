/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:33:39 by matde-ol          #+#    #+#             */
/*   Updated: 2023/12/01 18:07:38 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_security(char *reste, char *dest)
{
	if (reste == NULL || dest == NULL)
	{
		free(dest);
		free(reste);
		return (1);
	}
	return (0);
}

char	*ft_loop_buffer(int fd)
{
	ssize_t	size;
	char	*buffer;
	char	*next;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 || size == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[size] = 0;
	if (size == BUFFER_SIZE && ft_strchr_bis(buffer) == -1)
	{
		next = ft_loop_buffer(fd);
		if (next != NULL)
			buffer = ft_strjoin_f(buffer, next);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*reste;
	char		*dest;

	str = ft_loop_buffer(fd);
	if (reste != NULL && str != NULL)
		str = ft_strjoin_f(reste, str);
	else if (str == NULL && reste != NULL)
		str = reste;
	reste = NULL;
	if (str && ft_strchr_bis(str) != -1)
	{
		reste = ft_substr(str, ft_strchr_bis(str) + 1, ft_strlen(str));
		dest = ft_strlcpy_f(str, ft_strchr_bis(str) + 1);
		if (ft_security(reste, dest) == 1)
			return (NULL);
		if (reste != NULL && reste[0] == 0)
		{
			free(reste);
			reste = NULL;
		}
	}
	else
		dest = str;
	return (dest);
}
