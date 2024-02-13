/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:13:52 by jschaft           #+#    #+#             */
/*   Updated: 2023/10/16 14:54:56 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	get_word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*strdup_split(const char *src, int start, int len)
{
	char	*dst;
	int		i;

	dst = (char *)malloc(len + 1);
	if (dst == NULL)
	{
		free(dst);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		dst[i] = src[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	fill_re(char const *s, char c, char **re)
{
	int	i;
	int	y;
	int	start;

	i = 0;
	y = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			re[y] = strdup_split(s, start, i - start);
			if (re[y] == NULL)
				return ;
			y++;
		}
	}
	re[y] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**re;

	if (s == NULL)
		return (NULL);
	re = malloc(sizeof(char *) * (get_word_count(s, c) + 1));
	if (re == NULL)
	{
		free(re);
		return (NULL);
	}
	fill_re(s, c, re);
	return (re);
}
