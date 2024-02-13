/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:07:26 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:00 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**re;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	re = ft_split(path, ':');
	free(path);
	return (re);
}

int	search_path(char **path)
{
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		if (access(path[i], X_OK) >= 0)
			return (i);
		i++;
	}
	return (-1);
}

char	**cp_path(char **path)
{
	char	**re;
	int		i;

	i = 0;
	while (path[i] != NULL)
		i++;
	re = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (path[i] != NULL)
	{
		re[i] = ft_strdup(path[i]);
		i++;
	}
	re[i] == NULL;
	return (re);
}

char	**get_cmd(char **cmd)
{
	char	**re;
	int		i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	re = malloc(sizeof(char *) * (i - 1));
	i = 0;
	while (cmd[i] != NULL)
	{
		re[i] = ft_strdup(cmd[i]);
		i++;
	}
	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd[i]);
	return (re);
}
