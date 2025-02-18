/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:32:52 by zernest           #+#    #+#             */
/*   Updated: 2025/02/17 23:19:56 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data  data;

	if (ac != 6 && ac != 5)
	{
		ft_putstr_err("Invalid format");
	}
	init_struct(&data, av, ac);
	run_simulation(&data);
	// cleanup(&data)
	// - print_lock
	// --loop through the fork 
	pthread_mutex_destroy(&data.sim_lock);
	return (0);
}

long long current_timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}

void timer(long long ms)
{
	long long start = current_timestamp();
	while (current_timestamp() - start < ms)
	{
		usleep(10); // Sleep for 100 microseconds
	}
}

// static bool kill_philo(t_philo *philo)
// {
// 	time_t	time;

// 	time = current_timestamp();
// 	if ((time - philo->last_meal) >= philo->data->time_to_die)
// 	{
		
// 	}
// }