/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:08:38 by zernest           #+#    #+#             */
/*   Updated: 2025/02/21 15:18:12 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, int id, const char *action)
{
	pthread_mutex_lock(&data->printing_lock);
	pthread_mutex_lock(&data->sim_lock);
	if (data->simulation_end == 0)
		printf("%lld %d %s\n", current_timestamp()
			- data->start_time, id + 1, action);
	pthread_mutex_unlock(&data->sim_lock);
	pthread_mutex_unlock(&data->printing_lock);
}

static void	take_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
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
}

static void	release_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&data->forks[philo->left_fork_index]);
	pthread_mutex_unlock(&data->forks[philo->right_fork_index]);
}

// Refactored eat function using the helper functions.
void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	take_forks(philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = current_timestamp();
	pthread_mutex_unlock(&philo->meal_lock);
	print_action(data, philo->id, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	timer(data->time_to_eat);
	release_forks(philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = current_timestamp();
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->data->num_philo == 1)
		return (print_action(philo->data, 0, "died"),
			philo->data->simulation_end = 1, NULL);
	if ((philo->id + 1) % 2 == 0)
		timer(data->time_to_eat);
	while (!get_sim_status(data))
	{
		if (get_sim_status(data))
			break ;
		eat(philo);
		print_action(data, philo->id, "is sleeping");
		timer(data->time_to_sleep);
		print_action(data, philo->id, "is thinking");
	}
	return (NULL);
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

// void *end_checker(void *arg)
// {
// 	t_data *data = (t_data *)arg;
// 	int i;
// 	long long time_diff;

// 	while (!get_sim_status(data))
// 	{
// 		int finished;
// 		int i;

// 		finished = 1;
// 		i = 0;
// 		while (i < data->num_philo)
// 		{
// 			pthread_mutex_lock(&data->philo[i].meal_lock);
// 			time_diff = current_timestamp() - data->philo[i].last_meal;
// 			pthread_mutex_lock(&data->philo[i].meal_lock);
// 			if (time_diff > data->time_to_die)
// 			{
// 				//printf("troubleshoot: %d | %lld | %lld | %lld",
					//data->philo[i].id, time_diff,
					//data->philo[i].last_meal, current_timestamp());
// 				print_action(data, data->philo[i].id, "died");
// 				pthread_mutex_lock(&data->sim_lock);
// 				data->simulation_end = 1;
// 				pthread_mutex_unlock(&data->sim_lock);
// 				break;
// 			}
// 			i++;
// 		}
// 		if (data->amount_to_eat != -1)
// 		{
// 			i = 0;
// 			while (i < data->num_philo)
// 			{
// 				if (data->philo[i].meals_eaten < data->amount_to_eat)
// 				{
// 					finished = 0;
// 					break;
// 				}
// 				i++;
// 			}
// 			if (finished)
// 			{
// 				pthread_mutex_lock(&data->sim_lock);
// 				data->simulation_end = 1;
// 				pthread_mutex_unlock(&data->sim_lock);
// 			}
// 		}
// 		usleep(1000);
// 	}
// 	return (NULL);
// }

// void	eat(t_philo *philo)
// {
// 	t_data *data = philo->data;
// 	if (philo->left_fork_index < philo->right_fork_index)
// 	{
// 		pthread_mutex_lock(&data->forks[philo->left_fork_index]);
// 		print_action(data, philo->id, "has taken a fork");
// 		pthread_mutex_lock(&data->forks[philo->right_fork_index]);
// 		print_action(data, philo->id, "has taken a fork");
// 	}
// 	else
// 	{
// 		pthread_mutex_lock(&data->forks[philo->right_fork_index]);
// 		print_action(data, philo->id, "has taken a fork");
// 		pthread_mutex_lock(&data->forks[philo->left_fork_index]);
// 		print_action(data, philo->id, "has taken a fork");
// 	}
// 	pthread_mutex_lock(&philo->meal_lock);
// 	philo->last_meal = current_timestamp();
// 	pthread_mutex_unlock(&philo->meal_lock);
// 	print_action(data, philo->id, "is eating");
// 	pthread_mutex_lock(&philo->meal_lock);
// 	philo->meals_eaten++;
// 	pthread_mutex_unlock(&philo->meal_lock);
// 	timer(data->time_to_eat);
// 	pthread_mutex_unlock(&data->forks[philo->left_fork_index]);
// 	pthread_mutex_unlock(&data->forks[philo->right_fork_index]);
// }
