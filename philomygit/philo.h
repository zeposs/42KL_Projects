/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:22:12 by zernest           #+#    #+#             */
/*   Updated: 2025/02/20 20:50:09 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	int				meals_eaten;
	int				left_fork_index;
	int				right_fork_index;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t meal_lock;
} t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				amount_to_eat;
	int				simulation_end;
	long long		start_time;
	t_philo			philo[200];
	pthread_mutex_t *forks; 
	pthread_mutex_t printing_lock;
	pthread_mutex_t sim_lock;
}	t_data;

// utils
int		ft_strlen(char const *str);
void	ft_putstr_err(char *s);
int		ft_atoi(const char *str);
int		get_sim_status(t_data *data);

// init
void		init_struct(t_data *philo, char **av, int ac);
long long 	current_timestamp(void);
void 		timer(long long ms);
void		init_mutexes(t_data *data);
void		init_philo(t_data *data);
void		free_mutexes(t_data *data);
void		cleanup(t_data *data);

// routine
void		print_action(t_data *data, int id, const char *action);
void		eat(t_philo *philo);
void		*routine(void *arg);
void		*end_checker(void *arg);
void		run_simulation(t_data *data);

#endif