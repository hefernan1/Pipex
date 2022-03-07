/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:50:01 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/04 12:33:12 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	char	*get_cmd(char **paths, char *cmd)
{
	char		*tmp;
	char		*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	first_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_childs(&pipex);
		aff_msg(CMD_ERROR);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_childs(&pipex);
		aff_msg(CMD_ERROR);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
