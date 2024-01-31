/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:43:40 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/29 15:24:34 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_path(t_path **path)
{
	t_path	*path_next;

	if (path == NULL || *path == NULL)
		return ;
	while (*path != NULL)
	{
		path_next = (*path)->next;
		clear_split((*path)->cmd);
		free((*path)->path_all);
		free(*path);
		*path = path_next;
	}
}
void	clear_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	clear_data_path(t_data **data, t_path **path)
{
	clear_path(path);
	free((*data)->fd_pip);
	free(*data);
	ft_printf("Error\n");
	exit(0);
}
