/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:43:58 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/29 14:07:57 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ac_error(int nbr)
{
	if (nbr < 5)
		ft_printf("Too few argument\n");
	else
		ft_printf("Too many argument\n");
	exit(EXIT_FAILURE);
}

void	error_path_dir(char **all_dir, t_path *all_cmd, char *src, char **cmd)
{
	if (cmd != NULL)
		clear_split(cmd);
	if (src != NULL)
		free(src);
	clear_split(all_dir);
	clear_path(&all_cmd);
	ft_printf("Command does not found\n");
	exit(0);
}
