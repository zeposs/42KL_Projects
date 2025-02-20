/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:27:18 by zernest           #+#    #+#             */
/*   Updated: 2025/02/20 21:59:52 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, char **av, int ac)
{
	data->num_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->amount_to_eat = ft_atoi(av[5]);
		if (data->amount_to_eat < 0)
			ft_putstr_err("Error: Ensure proper philo format");
	}
	else
		data->amount_to_eat = -1;
	if (data->num_philo < 1 || data->num_philo > 200
		|| data->time_to_die < 60 || data->time_to_eat < 60 || data->time_to_sleep < 60)
		ft_putstr_err("At least one argument is invalid");
	init_mutexes(data);
	init_philo(data);
}

void	init_mutexes(t_data *data)
{
	int i;
	int error;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		ft_putstr_err("Error: Failed to allocate memory for mutex");
	while (i < data->num_philo)
	{
		error = pthread_mutex_init(&data->forks[i], NULL);
		if (error != 0)
			ft_putstr_err("Error: Failed to initialize mutex");
		i++;
	}
	error = pthread_mutex_init(&data->printing_lock, NULL);
	if (error != 0)
		ft_putstr_err("Error: Failed to initialize printing lock");
	error = pthread_mutex_init(&data->sim_lock, NULL);
	if (error != 0)
		ft_putstr_err("Error: Failed to initialize sim lock");
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].last_meal = 0;
		data->philo[i].meals_eaten = 0;
		data->philo[i].left_fork_index = i;
		data->philo[i].right_fork_index = (i + 1) % data->num_philo;
		data->philo[i].data = data;
		if (pthread_mutex_init(&data->philo[i].meal_lock, NULL) != 0)
		{
			ft_putstr_err("Error initializing meal lock");
			exit(1);
		}
		i++;
	}
}

void free_mutexes(t_data *data)
{
	int i;
	
	i = 0;
	while (i < data->num_philo)
	{
		printf("%s", "FREE LEAK");
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	// Destroy the printing and simulation locks.
	pthread_mutex_destroy(&data->printing_lock);
	pthread_mutex_destroy(&data->sim_lock);
	
	// Destroy each philosopher's meal lock.
	i = 0;
	// while (i < data->num_philo)
	// {
	// 	pthread_mutex_destroy(&data->philo[i].meal_lock);
	// 	i++;
	// }
	// Free the forks array.
	free(data->forks);
}

void cleanup(t_data *data)
{
	free_mutexes(data);  // This frees and destroys all mutexes and the forks array.
}
