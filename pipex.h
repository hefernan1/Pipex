/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:30:47 by hefernan          #+#    #+#             */
/*   Updated: 2022/03/04 12:38:09 by hefernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define INFILE_ERROR "Infile "
# define OUTFILE_ERROR "Outfile "
# define ARG_ERROR "Invalid number of arguments.\n"
# define PIPE_ERROR "Pipe "
# define CMD_ERROR "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		fd[2];
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	free_parent(t_pipex *pipex);
void	free_childs(t_pipex *pipex);
void	error_msg(char *str);
void	close_pipes(t_pipex *pipex);
int		aff_msg(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*find_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

#endif