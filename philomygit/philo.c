/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:32:52 by zernest           #+#    #+#             */
/*   Updated: 2025/02/21 15:17:34 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 6 && ac != 5)
		ft_putstr_err("Invalid format");
	init_struct(&data, av, ac);
	run_simulation(&data);
	cleanup(&data);
	return (0);
}

void	run_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	data->start_time = current_timestamp();
	data->simulation_end = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread,
				NULL, routine, &data->philo[i]) != 0)
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

long long	current_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	timer(long long ms)
{
	long long	start;

	start = current_timestamp();
	while (current_timestamp() - start < ms)
		usleep(10);
}
