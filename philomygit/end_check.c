/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 20:25:17 by zernest           #+#    #+#             */
/*   Updated: 2025/02/20 22:28:55 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_deaths(t_data *data)
{
	int i;
	long long diff;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->philo[i].meal_lock);
		diff = current_timestamp() - data->philo[i].last_meal;
		pthread_mutex_unlock(&data->philo[i].meal_lock);
		if (diff > data->time_to_die)
		{
			print_action(data, data->philo[i].id, "died");
			pthread_mutex_lock(&data->sim_lock);
			data->simulation_end = 1;
			pthread_mutex_unlock(&data->sim_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

static int check_meals(t_data *data)
{
	int i;
	int finished;

	if (data->amount_to_eat == -1)
		return (0);
	finished = 1;
	i = 0;
	while (i < data->num_philo)
	{
		if (get_philo_meal_count(&data->philo[i]) < data->amount_to_eat)
		{
			finished = 0;
			break;
		}
		i++;
	}
	if (finished)
	{
		pthread_mutex_lock(&data->sim_lock);
		data->simulation_end = 1;
		pthread_mutex_unlock(&data->sim_lock);
		return (1);
	}
	return (0);
}

void *end_checker(void *arg)
{
	t_data *data = (t_data *)arg;

	while (!get_sim_status(data))
	{
		if (check_deaths(data) || check_meals(data))
			break;
		usleep(1000);
	}
	return (NULL);
}

int	get_philo_meal_count(t_philo *philo)
{
	int meal_count;

	pthread_mutex_lock(&philo->meal_lock);
	meal_count = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_lock);

	return (meal_count);
}
