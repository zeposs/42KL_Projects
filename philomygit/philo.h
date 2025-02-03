/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:22:12 by zernest           #+#    #+#             */
/*   Updated: 2025/02/04 06:20:08 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
    int     num;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     amount_to_eat;
}	t_philo;

// utils
int		ft_strlen(char const *str);
void	ft_putstr_err(char *s);
int	    ft_atoi(const char *str);

// init
void    init_struct(t_philo *philo, char **av, int ac);

#endif