/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:55:58 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/30 13:43:35 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_fd(t_data *data)
{
	ft_putnbr_fd(data->fd_in, 2);
	ft_putnbr_fd(data->fd_pip[1], 2);
	if (dup2(data->fd_in, STDIN) == -1)
		return (-1);
	if (dup2(data->fd_pip[1], STDOUT) == -1)
		return (-1);
	close(data->fd_in);
	//ft_putendl_fd("first", 2);
	return (0);
}

static int	last_fd(t_data *data, int i)
{
	ft_putnbr_fd(data->fd_pip[i], 2);
	ft_putnbr_fd(data->fd_pip[i+1], 2);
	if (dup2(data->fd_pip[i], STDIN) == -1)
		return (-1);
	if (dup2(data->fd_out, STDOUT) == -1)
		return (-1);
	//ft_putendl_fd("last", 2);
	close(data->fd_pip[data->fd_pip[i - 1]]);
	return (0);
}

static int	other_fd(int i, t_data *data)
{
	ft_putnbr_fd(data->fd_pip[i], 2);
	ft_putnbr_fd(data->fd_pip[i+1], 2);
	if (dup2(data->fd_pip[i], STDIN) == -1)
		return (-1);
	if (dup2(data->fd_pip[i + 1], STDOUT) == -1)
		return (-1);
	//ft_printf("other fd : %d\n", data->fd_pip[i]);
	close(data->fd_pip[i - 1]);
	return (0);
}

static int	exec_cmd(int i, t_data *data, t_path *path)
{		
	if (i == 0)
	{
		if (first_fd(data) == -1)
			clear_data_path(&data, &path);
	}
	if (i == data->nbr_pip)
	{
		//ft_putendl_fd("last", 2);
		if (last_fd(data, i) == -1)
			clear_data_path(&data, &path);
	}
	else
	{
		//ft_putendl_fd("vewq", 2);
		if (other_fd(i, data) == -1)
			clear_data_path(&data, &path);
	}
	execve(path->path_all, path->cmd, data->envp);
	return (0);
}

void	exec_cmd_to_fd(t_data *data, t_path *path)
{
	int	i;

	i = 0;
	while (i < data->nbr_pip)
	{
		//ft_putendl_fd("ici", 2);
		//ft_putnbr_fd(data->nbr_pip, 2);
		data->pid = fork();
		if (data->pid == 0)
		{
			if (exec_cmd(i, data, path) == -1)
				clear_data_path(&data, &path);
		}
		i++;
	}
	while (i >= 1)
	{
		waitpid(data->pid, NULL, 0);
		i--;
	}
	clear_path(&path);
	close(data->fd_out);
	close(data->fd_pip[i]);
	free(data->fd_pip);
	free(data);
}
