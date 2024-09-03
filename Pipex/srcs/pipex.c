/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:40:22 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/13 16:13:54 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex(int arg, char **argv, char *envp[])
{
	int		fd[2];
	pid_t	pid;

	(void)arg;
	if (pipe(fd) == -1)
		ft_perror("pipe");
	pid = fork();
	if (pid == -1)
		ft_perror("fork");
	if (pid == 0)
	{
		ft_proccess_child(fd, argv, envp);
	}
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
			ft_perror("waitpid");
		ft_proccess_parent(fd, argv, envp);
	}
}

int	main(int arg, char **argv, char **envp)
{
	if (arg == 5)
	{
		pipex(arg, argv, envp);
	}
	else
	{
		ft_put_error();
	}
	return (0);
}
