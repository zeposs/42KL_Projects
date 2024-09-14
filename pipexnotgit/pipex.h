/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:31:58 by zernest           #+#    #+#             */
/*   Updated: 2024/09/14 19:45:10 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

//pipex
char	*get_path(char **env, char *cmd);
void	child(int *pipe_fd, char **av, char **envp);

//utils
void	ft_putstr_err(char *s);
void	exit_error_str(char *str, int n);

#endif