/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpinho-c <cpinho-c@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-06 14:50:15 by cpinho-c          #+#    #+#             */
/*   Updated: 2025-05-06 14:50:15 by cpinho-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

void	check_valid_files(char *infile, char *outfile)
{
	int	fd;
	if (access(infile, F_OK) != 0 || access(infile, R_OK) != 0)
		call_error(0);
	if (access(outfile, F_OK) != 0)
	{
		fd = open(outfile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd == -1)
			call_error(9);
		else
			close(fd);
	}
	if (access(outfile, W_OK) != 0)
		call_error(1);
}
void	free_split(char **splitpath)
{
	int	i;

	i = 0;
	while (splitpath[i])
	{
		free(splitpath[i]);
		i++;
	}
	free(splitpath);
}

void	free_struct(t_list *cmd_info)
{
	int	i;

	i = 0;
	while (cmd_info->cmd1[i])
	{
		free(cmd_info->cmd1[i]);
		i++;
	}
	free(cmd_info->cmd1);
	i = 0;
	while (cmd_info->cmd2[i])
	{
		free(cmd_info->cmd2[i]);
		i++;
	}
	free(cmd_info->cmd2);
	free(cmd_info->cmd1path);
	free(cmd_info->cmd2path);
	free(cmd_info);
}

void	call_error(int type)
{
	if (type == 0)
		perror("infile does not exist/is not readable");
	if (type == 1)
		perror("no write permission on outfile");
	if (type == 2)
		perror("Failed to create struct");
	if (type == 3)
		perror("Command not found");
	if (type == 4)
		perror("Failed to create pipe");
	if (type == 5)
		perror("Failed to open infile");
	if (type == 6)
		perror("Failed to execute first command");
	if (type == 7)
		perror("Failed to open outfile");
	if (type == 8)
		perror("Failed to execute second command");
	if (type == 9)
		perror("Failed to create outfile");
	exit (1);
}
