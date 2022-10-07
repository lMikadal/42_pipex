/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:21:46 by pmikada           #+#    #+#             */
/*   Updated: 2022/09/21 15:21:58 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == 39)
		{
			word++;
			i++;
			while (s[i] != 39)
				i++;
			i++;
		}
		else if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_loc_string(char *s, int start, int end)
{
	char	*m;
	int		i;

	i = 0;
	if (s[end - 1] == 39)
		end--;
	m = (char *)malloc((end - start + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	while (start < end)
		m[i++] = s[start++];
	m[i] = '\0';
	return (m);
}

static void	ft_ma(char ***m, char *s, char c)
{
	*m = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (*m == NULL)
		return ;
}

char	**ft_split(char *s, char c)
{
	char	**m;
	int		i;
	int		start;
	int		word;

	m = NULL;
	ft_ma(&m, s, c);
	i = -1;
	word = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] == 39)
		{
			start = ++i;
			while (s[i] != 39)
				i++;
			i++;
		}
		else if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (i != 0 && s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			m[word++] = ft_loc_string(s, start, i);
	}
	m[word] = 0;
	return (m);
}
