/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:36:08 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/28 12:08:19 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**init_dir(char **src)
{
	int		i;
	char	*tmp;

	i = 0;
	while (src[i] != NULL)
	{
		tmp = src[i];
		tmp = ft_strjoin(src[i], "/");
		free(src[i]);
		src[i] = tmp;
		i++;
	}
	return (src);
}

char    **split_envp(char **envp)
{
	int		i;
	char	**all_dir;

    i = 0;
    while(ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	all_dir = ft_split(envp[i] + 5, ':');
	init_dir(all_dir);
    return (all_dir);
}

