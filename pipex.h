/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:05:47 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/19 11:05:50 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_list
{
	char	**path;
	char	***cmd;
	char	**path_cmd;
}	t_list;

typedef struct s_data
{
	int	in;
	int	out;
}	t_data;

void	ft_process(t_list *lst, char **envp, t_data *fd);
void	ft_process2(int *pipe_fd, t_data *fd, t_list *lst, char **envp);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr(char *s);
char	**ft_split(char *s, char c);
void	ft_free(t_list *lst, int mode);
void	ft_free_cmd(char ***s);
void	ft_free_split(char **s);
void	ft_free_some(char **s);
void	ft_err_not_cmd(t_list *lst, int *err);
void	ft_err_file(int *err, char *s);
void	ft_err(t_list *lst, t_data *fd);

#endif
