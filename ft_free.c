/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:44:20 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/21 15:44:31 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(t_list *lst, int mode)
{
	if (mode == 0)
		ft_free_split(lst->path);
	else if (mode == 1)
	{
		ft_free_split(lst->path);
		ft_free_cmd(lst->cmd);
		ft_free_some(lst->path_cmd);
	}
	else if (mode == 2)
	{
		ft_free_cmd(lst->cmd);
		ft_free_some(lst->path_cmd);
	}
}

void	ft_free_cmd(char ***s)
{
	int	i;

	i = 0;
	while (s[i])
		ft_free_split(s[i++]);
	free(s);
}

void	ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

void	ft_free_some(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] != '-')
			free(s[i]);
		i++;
	}
	free(s);
}
