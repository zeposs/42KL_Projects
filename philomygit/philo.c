/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:32:52 by zernest           #+#    #+#             */
/*   Updated: 2025/02/14 17:33:08 by zernest          ###   ########.fr       */
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
	return (0);
}

long long current_timestamp(void)
{
	struct timeval tv;
	long long int milisec;

	gettimeofday(&tv, NULL);
	milisec = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (milisec);
}

void timer(long long ms)
{
	long long start = current_timestamp();
	while (current_timestamp() - start < ms)
	{
		usleep(100); // Sleep for 100 microseconds
	}
}
