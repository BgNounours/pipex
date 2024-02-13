/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:07:26 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:00 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	child(char **path, char **av, char **envp, int pipes[2])
{
	char	**p;
	char	**cmd;
	int		fd;
	int		i;

	fd = open(av[1], O_RDONLY);
	dup2(fd, 0);
	dup2(pipes[1], 1);
	p = cp_path(path);
	i = 0;
	while (p[i] != NULL)
	{
		p[i] = ft_strjoin(p[i], "/");
		p[i] = ft_strjoin(p[i], av[2]);
		i++;
	}
	i = search_path(p);
	cmd = get_cmd(ft_split(av[2], ' '));
	close(pipes[0]);
	execve(p[i], cmd, envp);
}

static void	parent(char **path, char **av, char **envp, int pipes[2])
{
	int		i;
	int		fd;
	char	**cmd;

	i = 0;
	fd = open(av[4], O_WRONLY, O_CREAT, O_TRUNC);
	dup2(pipes[0], 0);
	dup2(fd, 1);
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], av[3]);
		i++;
	}
	cmd = get_cmd(ft_split(av[3], ' '));
	i = search_path(path);
	close(pipes[1]);
	execve(path[i], cmd, envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pipes[2];
	char	**path;
	pid_t	p;

	if (ac != 5)
		return (0);
	if (access(av[1], R_OK) < 0)
		return (0);
	if (pipe(pipes) < 0)
		return (0);
	path = get_path(envp);
	p = fork();
	if (p < 0)
		return (0);
	if (p == 0)
		child(path, av, envp, pipes);
	parent(path, av, envp, pipes);
}
