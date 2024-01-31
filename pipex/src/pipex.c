/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:04:11 by matde-ol          #+#    #+#             */
/*   Updated: 2024/01/30 13:23:40 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static int	init_fd(t_data *data, char **av, int ac)
{
	int	*tab;

	if (data == NULL)
		return (-1);
	data->fd_in = open(av[1], O_RDONLY);
	data->fd_out = open(av[ac - 1], O_RDONLY);
	data->nbr_pip = ac - 4;
	tab = malloc(sizeof(int) * (data->nbr_pip * 2));
	if (tab == NULL)
	{
		free(data);
		return (-1);
	}
	data->fd_pip = tab;
	return (0);
}

static void	error_file(t_path *all_path)
{
	clear_path(&all_path);
	ft_printf("Error with file descriptor\n");
	exit(0);
}

static void	check_fd(char **av, int ac, t_path *all_path)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		i++;
	close(fd);
	fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
		i++;
	close(fd);
	if (i != 0)
		error_file(all_path);
}

int	main(int ac, char **av, char **envp)
{
	t_path	*all_path;
	char	**splited_envp;
	t_data	*data;

	if (envp[0] == NULL)
		return (0);
	if (ac != 5)
		ac_error(ac);
	splited_envp = split_envp(envp);
	all_path = init_lst(ac, av, splited_envp);
	check_fd(av, ac, all_path);
	data = malloc(sizeof(t_data));
	if (init_fd(data, av, ac) == -1)
	{
		clear_path(&all_path);
		ft_printf("Error\n");
		exit(0);
	}
	data->name_prog = av[0];
	data->envp = envp;
	if (pipe(data->fd_pip) == -1)
		clear_data_path(&data, &all_path);
	exec_cmd_to_fd(data, all_path);
}
	// t_path	*chekpoint = all_path;
	//clear_path(&all_path);
	// clear_path(&chekpoint);
	// while (all_path != NULL)
	// {
	// 	printf("%s\n", all_path->path_all);
	// 	printf("%s\n", all_path->cmd[0]);
	// 	//printf("%s\n", all_path->cmd[1]);
	// 	all_path = all_path->next;
	// }
	// printf("%s\n", envp[i]);
	// printf("%d\n", access("/nfs/homes/matde-ol/.local/bin/cat", F_OK));
	// printf("%d\n", access("/nfs/homes/matde-ol/bin/cat", F_OK));
	// printf("%d\n", access("/usr/local/sbin/cat", F_OK));
	// printf("%d\n", access("/usr/local/bin/cat", F_OK));
	// printf("%d\n", access("/usr/sbin/cat", F_OK));
	// printf("%d\n", access("/usr/bin/cat", F_OK));
	// printf("%d\n", access("/sbin/cat", F_OK));
	// printf("%d\n", access("/bin/cat", F_OK));
	// printf("%d\n", access("/usr/games/cat", F_OK));
	// printf("%d\n", access("/usr/local/games/cat", F_OK));
	// printf("%d\n", access("/snap/bin/cat", F_OK));