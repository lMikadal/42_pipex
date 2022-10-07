/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:31:08 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/21 16:31:20 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*m;
	int		sumlen;
	int		i;
	int		j;

	sumlen = ft_strlen(s1) + ft_strlen(s2);
	m = (char *)malloc((sumlen + 2) * sizeof (char));
	if (m == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		m[i] = s1[i];
		i++;
	}
	m[i++] = '/';
	while (j < ft_strlen(s2))
		m[i++] = s2[j++];
	m[i] = '\0';
	return (m);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(2, &s[i++], 1);
}
