/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:20:41 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/22 14:20:57 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_err_not_cmd(t_list *lst, int *err)
{
	int	i;

	i = 0;
	if (*err > 0)
		i = 1;
	while (lst->path_cmd[i])
	{
		if (lst->path_cmd[i][0] == '-')
		{
			ft_putstr("zsh: command not found: ");
			ft_putstr(lst->cmd[i][0]);
			write(2, "\n", 1);
			*err += 1;
		}
		i++;
	}
}

void	ft_err_file(int *err, char *s)
{
	ft_putstr("zsh: no such file or directory: ");
	ft_putstr(s);
	write(2, "\n", 1);
	*err += 1;
}

void	ft_err(t_list *lst, t_data *fd)
{
	ft_free(lst, 1);
	close(fd->in);
	close(fd->out);
	exit(0);
}
