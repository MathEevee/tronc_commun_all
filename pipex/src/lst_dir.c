/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:07:34 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/28 14:40:41 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	save_cmd(t_path **path_cmd, t_path *new)
{
	if (path_cmd == NULL)
		return ;
	if (*path_cmd == NULL)
		*path_cmd = new;
	else if ((*path_cmd)->path_all == NULL && (*path_cmd)->cmd == NULL)
		(*path_cmd) = new;
	else if ((*path_cmd)->next == NULL)
		(*path_cmd)->next = new;
	else
		save_cmd(&(*path_cmd)->next, new);
}

static t_path	*new_cmd(char *path, char **cmd)
{
	t_path	*new;

	new = malloc(sizeof(t_path));
	if (new == NULL)
		return (NULL);
	new->path_all = path;
	new->cmd = cmd;
	new->next = NULL;
	return (new);
}

static char	*check_path(char **path, char **cmd)
{
	int		i;
	char	*access_path;

	i = 0;
	while (path[i] != NULL)
	{
		access_path = ft_strjoin(path[i], cmd[0]);
		if (access(access_path, X_OK) == 0)
			return (access_path);
		free(access_path);
		i++;
	}
	return (NULL);
}

t_path	*init_lst(int ac, char **av, char **all_dir)
{
	int		i;
	char	**cmd;
	t_path	*path;
	char	*src;

	i = 2;
	path = NULL;
	while (i < ac - 1)
	{
		cmd = ft_split(av[i], ' ');
		src = check_path(all_dir, cmd);
		if (src == NULL || cmd == NULL)
			error_path_dir(all_dir, path, src, cmd);
		save_cmd(&path, new_cmd(src, cmd));
		i++;
	}
	clear_split(all_dir);
	return (path);
}
