/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:21:52 by zernest           #+#    #+#             */
/*   Updated: 2024/07/28 19:46:27 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*ft_readfile(int fd, char *stash);
char	*get_line(char *stash);
char	*process_stash(char *stash);
char	*get_next_line(int fd);

// utils
int		ft_strlen(char const *str);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strchr(char *str, int c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, int start, int len);

#endif