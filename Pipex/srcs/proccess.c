/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:00:35 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/13 00:09:57 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_is_path(char **envp)
{
	int		i;
	char	*my_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			my_path = envp[i] + 5;
			return (my_path);
		}
		i++;
	}
	return (NULL);
}

static char	*ft_find_path(char *cmd, char **envp)
{
	int		j;
	char	**path;
	char	*path_cmd;

	path = ft_split(ft_is_path(envp), ':');
	if (!path)
		return (NULL);
	j = 0;
	while (path[j])
	{
		path_cmd = build_path_cmd(path[j], cmd);
		if (path_cmd && access(path_cmd, R_OK | F_OK | X_OK) == 0)
		{
			ft_free(path);
			return (path_cmd);
		}
		free(path_cmd);
		j++;
	}
	ft_free(path);
	return (NULL);
}

void	ft_execute(char *cmd, char *envp[])
{
	char	**my_cmd;
	char	*path;

	my_cmd = ft_split(cmd, ' ');
	if (!my_cmd || !my_cmd[0])
	{
		ft_free(my_cmd);
		exit(EXIT_FAILURE);
	}
	path = ft_find_path(my_cmd[0], envp);
	ft_execute_command(path, my_cmd, envp);
	free(path);
	ft_free(my_cmd);
}

void	ft_proccess_child(int fd[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_perror(argv[1]);
	if (dup2(infile, 0) == -1 || dup2(fd[1], 1) == -1)
		ft_perror("dup2");
	close(fd[0]);
	close(infile);
	close(fd[1]);
	ft_execute(argv[2], envp);
}

void	ft_proccess_parent(int fd[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_perror(argv[4]);
	if (dup2(fd[0], 0) == -1 || dup2(outfile, 1) == -1)
		ft_perror("dup2");
	close(fd[1]);
	close(outfile);
	close(fd[0]);
	ft_execute(argv[3], envp);
}
