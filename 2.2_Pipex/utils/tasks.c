/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-08 14:30:49 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-08 14:30:49 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

char	*get_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_truepath(char *cmd, char *fullpath)
{
	char	**splitpath;
	char	*truepath;
	char	*temp;
	int		i;
	
	splitpath = ft_split(fullpath, ':');
	i = 0;
	while (splitpath[i])
	{
		truepath = ft_strjoin(splitpath[i], "/");
		temp = truepath;
		truepath = ft_strjoin(temp, cmd);
		free(temp);
		if (access(truepath, X_OK) == 0)
		{
			free_split(splitpath);
			return (truepath);
		}
		free(truepath);
		i++;
	}
	free_split(splitpath);
	call_error(3);
	exit(1);
}

void	exec_cmd1(t_list *cmd_info, int pipe_fd[2], char *envp[])
{
	int	in_fd;

	if (fork() == 0)
	{
		in_fd = open(cmd_info->infile, O_RDONLY);
		if(in_fd == 1)
			call_error(5);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
		execve(cmd_info->cmd1path, cmd_info->cmd1, envp);
		call_error(6);
	}
}

void	exec_cmd2(t_list *cmd_info, int pipe_fd[2], char *envp[])
{
	int		out_fd;

	if (fork() == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		out_fd = open(cmd_info->outfile, O_WRONLY | O_TRUNC);
		if(out_fd == -1)
			call_error(7);
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
		execve(cmd_info->cmd2path, cmd_info->cmd2, envp);
		call_error(8);
	}
}
