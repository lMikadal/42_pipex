/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:03:50 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/19 11:03:52 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process(t_list *lst, char **envp, t_data *fd)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit (0);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd->in, 0);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(lst->path_cmd[0], lst->cmd[0], envp);
	}
	else if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		ft_process2(pipe_fd, fd, lst, envp);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(fd->in);
		close(fd->out);
	}
}

void	ft_process2(int *pipe_fd, t_data *fd, t_list *lst, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(pipe_fd[0], 0);
		dup2(fd->out, 1);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve(lst->path_cmd[1], lst->cmd[1], envp);
	}
	else if (pid > 0)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		waitpid(pid, NULL, 0);
	}
}
