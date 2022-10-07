/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:03:32 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/19 11:03:34 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_path(t_list *lst, char **envp)
{
	int	i;

	i = 0;
	while (envp[i][0] != 'P' && envp[i][1] != 'A')
		i++;
	lst->path = ft_split(&envp[i][5], ':');
}

static void	ft_cmd(t_list *lst, int ac, char **av)
{
	int	i;

	lst->cmd = (char ***)malloc((ac - 2) * sizeof(char **));
	if (lst->cmd == NULL)
		return ;
	i = 0;
	while (i + 2 < ac - 1)
	{
		lst->cmd[i] = ft_split(av[i + 2], ' ');
		i++;
	}
	lst->cmd[i] = NULL;
}

static char	*ft_add_path_cmd(t_list *lst, char *s)
{
	int		i;
	char	*path;

	path = NULL;
	i = 0;
	while (lst->path[i])
	{
		path = ft_strjoin("", s);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		path = ft_strjoin(lst->path[i], s);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		i++;
		free(path);
	}
	return ("-");
}

static void	ft_chk_path(t_list *lst, int *err)
{
	int	len;
	int	i;

	len = 0;
	while (lst->path[len])
		len++;
	lst->path_cmd = (char **)malloc(sizeof(char *) * (len + 1));
	if (lst->path_cmd == NULL)
		return ;
	i = 0;
	while (lst->cmd[i])
	{
		lst->path_cmd[i] = ft_add_path_cmd(lst, lst->cmd[i][0]);
		i++;
	}
	lst->path_cmd[i] = NULL;
	i = -1;
	while (lst->path_cmd[++i])
	{
		if (lst->path_cmd[i][0] == '-')
		{
			ft_err_not_cmd(lst, err);
			break ;
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_list	lst;
	t_data	fd;
	int		err;

	if (ac == 5)
	{
		err = 0;
		ft_path(&lst, envp);
		ft_cmd(&lst, ac, av);
		fd.in = open(av[1], O_RDWR);
		if (fd.in == -1)
			ft_err_file(&err, av[1]);
		fd.out = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
		ft_chk_path(&lst, &err);
		if (err > 0)
			ft_err(&lst, &fd);
		ft_free(&lst, 0);
		ft_process(&lst, envp, &fd);
		ft_free(&lst, 2);
	}
	else
		write(2, "argument not correct\n", 21);
	return (0);
}
