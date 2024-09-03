/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandriam <sandriam@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:56:33 by sandriam          #+#    #+#             */
/*   Updated: 2024/08/13 00:10:56 by sandriam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/wait.h>

void	pipex(int arg, char **argv, char *envp[]);
void	ft_put_error(void);
void	ft_proccess_child(int fd[2], char **argv, char **envp);
void	ft_proccess_parent(int fd[2], char **argv, char **envp);
void	ft_perror(char *msg);
void	ft_free(char **str);
void	ft_execute_command(char *path, char **my_cmd, char **envp);

char	*build_path_cmd(char *path, char *cmd);

#endif