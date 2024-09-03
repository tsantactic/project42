/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:40:17 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/13 16:16:12 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_perror(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_put_error(void)
{
	ft_putstr_fd("Error bad arguments,the program takes 4 arguments.\n", 1);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	exit(1);
}

char	*build_path_cmd(char *path, char *cmd)
{
	char	*part_path;
	char	*path_cmd;

	part_path = ft_strjoin(path, "/");
	if (!part_path)
		return (NULL);
	path_cmd = ft_strjoin(part_path, cmd);
	free(part_path);
	return (path_cmd);
}

void	ft_execute_command(char *path, char **my_cmd, char **envp)
{
	if (!path)
	{
		ft_putstr_fd(my_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free(my_cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, my_cmd, envp) == -1)
	{
		ft_perror("execve");
		ft_free(my_cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
}
