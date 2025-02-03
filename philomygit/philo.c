/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:32:52 by zernest           #+#    #+#             */
/*   Updated: 2025/02/04 06:20:52 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo philo;

    if (ac != 6 && ac != 5)
    {
        ft_putstr_err("Invalid format");
    }
    init_struct(&philo, av, ac);
    return (0);
}