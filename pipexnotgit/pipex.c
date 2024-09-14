/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:16:54 by zernest           #+#    #+#             */
/*   Updated: 2024/09/14 20:07:47 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char **env, char *cmd)
{
	char	**available_paths;
	char	*current_path;
	char	*full_path;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	current_path = ft_substr(env[i], 5, ft_strlen(env[i]));
	available_paths = ft_split(current_path, ':');
	i = 0;
	while (available_paths[i])
	{
		full_path = ft_strjoin(ft_strjoin(available_paths[i], "/"), cmd);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
	}
	free_available_paths(available_paths);
	exit_error_str(cmd, 1);
	return (NULL);
}

void	execute(char *str, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(str, ' ');
	path = get_path(env, cmd[0]);
	if (execve(path, cmd, env) == -1)
		perror("Error");
}

void	child(int *pipe_fd, char **av, char **env)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		exit_error_str(av[1], 2);
	close(pipe_fd[0]);
	dup2(infile, 0);
	dup2(pipe_fd[1], 1);
	execute(av[2], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("Error");
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{
		child(pipe_fd, av, env);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
