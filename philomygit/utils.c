/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:41:26 by zernest           #+#    #+#             */
/*   Updated: 2025/02/21 15:18:24 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_err(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	write(2, s, len);
	write(2, "\n", 1);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	countneg;

	countneg = 0;
	i = 0;
	num = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			countneg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (countneg > 1)
		return (0);
	else if (countneg == 1)
		return (num * -1);
	return (num);
}

int	get_sim_status(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->sim_lock);
	status = data->simulation_end;
	pthread_mutex_unlock(&data->sim_lock);
	return (status);
}

int	get_philo_meal_count(t_philo *philo)
{
	int	meal_count;

	pthread_mutex_lock(&philo->meal_lock);
	meal_count = philo->meals_eaten;
	pthread_mutex_unlock(&philo->meal_lock);
	return (meal_count);
}
