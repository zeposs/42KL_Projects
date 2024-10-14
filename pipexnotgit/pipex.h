/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:31:58 by zernest           #+#    #+#             */
/*   Updated: 2024/09/20 20:36:41 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//pipex
char	*get_path(char **env, char *cmd);
void	execute(char *str, char **env);
void	child(int *pipe_fd, char **av, char **envp);
void	parent(int *pipe_fd, char **av, char **env);

//utils
void	ft_putstr_err(char *s);
void	exit_error_str(char *str, int n);
void	free_available_paths(char **str);

#endif