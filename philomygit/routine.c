/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:08:38 by zernest           #+#    #+#             */
/*   Updated: 2025/02/17 23:12:51 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_action(t_data *data, int id, const char *action)
{
	pthread_mutex_lock(&data->printing_lock);
	pthread_mutex_lock(&data->sim_lock);
	if (data->simulation_end == 0)
		printf("%lld %d %s\n", current_timestamp()
	- data->start_time, id + 1, action);
	pthread_mutex_unlock(&data->sim_lock);
	pthread_mutex_unlock(&data->printing_lock);
}

// void eat(t_philo *philo)
// {
// 	t_data	*data = philo->data;

// 	pthread_mutex_lock(&data->forks[philo->left_fork_index]);
// 	print_action(data, philo->id, "has taken a fork");
// 	pthread_mutex_lock(&data->forks[philo->left_fork_index]);
// 	print_action(data, philo->id, "has taken a fork");
// 	philo->last_meal = current_timestamp;
// 	print_action(data, philo->id, "is eating");
// 	timer(data->time_to_eat);
// 	philo->meals_eaten;
// 	pthread_mutex_unlock(&data->forks[philo->left_fork_index]);
// 	pthread_mutex_unlock(&data->forks[philo->right_fork_index]);
// }

void eat(t_philo *philo)
{
    t_data *data = philo->data;
    
    // Determine the order based on fork IDs.
    if (philo->left_fork_index < philo->right_fork_index)
    {
        pthread_mutex_lock(&data->forks[philo->left_fork_index]);
        print_action(data, philo->id, "has taken a fork");
        pthread_mutex_lock(&data->forks[philo->right_fork_index]);
        print_action(data, philo->id, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(&data->forks[philo->right_fork_index]);
        print_action(data, philo->id, "has taken a fork");
        pthread_mutex_lock(&data->forks[philo->left_fork_index]);
        print_action(data, philo->id, "has taken a fork");
    }
    
    // Now eat
    philo->last_meal = current_timestamp();
    print_action(data, philo->id, "is eating");
    philo->meals_eaten++;
    timer(data->time_to_eat);
    
    // Release forks
    pthread_mutex_unlock(&data->forks[philo->left_fork_index]);
    pthread_mutex_unlock(&data->forks[philo->right_fork_index]);
}

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data *data = philo->data;

	philo->last_meal = current_timestamp;
	if (philo->id % 2 == 0)
	{
		print_action(data, philo->id, "is thinking");
		timer(data->time_to_eat);
	}
	while (!data->simulation_end)
	{
		if (data->simulation_end)
			break;
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->time_to_sleep);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
}

void *end_checker(void *arg)
{
	t_data *data = (t_data *)arg;
	int i;
	
	while (!data->simulation_end)
	{
		int finished;
		int i;

		finished = 1;
		i = 0;
		while (i < data->num_philo)
		{
			if (current_timestamp() - data->philo[i].last_meal > data->time_to_die)
			{
				print_action(data, data->philo[i].id, "died");
				pthread_mutex_lock(&data->sim_lock);
				data->simulation_end = 1;
				pthread_mutex_unlock(&data->sim_lock);
				break;
			}
			i++;
		}
		if (data->amount_to_eat != -1)
		{
			i = 0;
			while (i, data->num_philo)
			{
				if (data->philo[i].meals_eaten < data->amount_to_eat)
				{
					finished = 0;
					break;
				}
			}
			if (finished)
				data->simulation_end = 1;
		}
		usleep(1000);
	}
	return (NULL);
}

void run_simulation(t_data *data)
{
	int			i;
	pthread_t 	monitor;

	i = 0;
	data->start_time = current_timestamp();
	data->simulation_end = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]) != 0)
			ft_putstr_err("Error creating philo thread");
		i++;
	}
	if (pthread_create(&monitor, NULL, end_checker, data) != 0)
		ft_putstr_err("Error creating philo thread");
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}
