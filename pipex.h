/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:07:26 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 11:09:00 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/wait.h>

char	**get_path(char **envp);
int		search_path(char **path);
char	**cp_path(char **path);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *s);
char	*ft_strdup(const char *s);

#endif