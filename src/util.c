/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:07:26 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:00 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	int				i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	while (st1[i] == st2[i] && st1[i] != '\0' && st2[i] != '\0'
		&& i < (int)n - 1)
		i++;
	return (st1[i] - st2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*null_re;
	char	*re;

	i = 0;
	null_re = malloc(sizeof(char));
	re = malloc(sizeof(char) * (len + 1));
	if (re == NULL || null_re == NULL)
		return (NULL);
	null_re[0] = '\0';
	if (start >= ft_strlen(s))
		return (null_re);
	while (s[i + start] != '\0' && i < (int)len)
	{
		re[i] = s[i + start];
		i++;
	}
	re[i] = '\0';
	return (re);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	int		size;
	char	*re;

	i = 0;
	y = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	re = malloc(sizeof(char) * size);
	if (re == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		re[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		re[i + y] = s2[y];
		y++;
	}
	re[i + y] = '\0';
	return (re);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*re;

	len = 0;
	while (s[len] != '\0')
		len++;
	re = malloc(sizeof(char) * (len + 1));
	if (re == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		re[i] = s[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
