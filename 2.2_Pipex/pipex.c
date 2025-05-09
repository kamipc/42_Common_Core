/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 13:26:07 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-06 13:26:07 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

t_list	*init_struct(char **args, char *envp[])
{
	t_list	*cmd_info;

	cmd_info = malloc(sizeof(t_list));
	if (!cmd_info)
		call_error(2);
	cmd_info->cmd1 = ft_split(args[2], ' ');
	cmd_info->cmd2 = ft_split(args[3], ' ');
	cmd_info->cmd1path = find_truepath(cmd_info->cmd1[0], get_path(envp));
	cmd_info->cmd2path = find_truepath(cmd_info->cmd2[0], get_path(envp));
	cmd_info->infile = args[1];
	cmd_info->outfile = args[4];

	return (cmd_info);
}

int	main(int ac, char **av, char *envp[])
{
	t_list	*cmd_info;
	int		pipe_fd[2];

	if (ac != 5)
		return (0);
	check_valid_files(av[1], av[4]);
	cmd_info = init_struct(av, envp);
	if (pipe(pipe_fd) == -1)
		call_error(4);
	exec_cmd1(cmd_info, pipe_fd, envp);
	exec_cmd2(cmd_info, pipe_fd, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	free_struct(cmd_info);
}
