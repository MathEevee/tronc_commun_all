/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:58:59 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/30 13:21:41 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../Libft/libft.h"
# include <stddef.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
# define STDIN 0
# define STDOUT 1

typedef struct s_data
{
	int		pid;
	int		fd_in;
	int		fd_out;
	int		*fd_pip;
	int		nbr_pip;
	char	*name_prog;
	char	**envp;
}	t_data;

typedef struct s_path
{
	char			*path_all;
	char			**cmd;
	struct s_path	*next;
}	t_path;

/*error.c*/
void	ac_error(int nbr);

t_path	*init_lst(int ac, char **av, char **all_dir);

char    **split_envp(char **envp);

void	error_path_dir(char **all_dir, t_path *all_cmd, char *src, char **cmd);
void	clear_split(char **tab);
void	clear_path(t_path **path);
void	clear_data_path(t_data **data, t_path **path);
void	exec_cmd_to_fd(t_data *data, t_path *path);
#endif