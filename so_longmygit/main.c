/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:14 by zernest           #+#    #+#             */
/*   Updated: 2024/12/12 17:06:26 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	init_mlx(ac, av, &mlx);
	init_map(&mlx, av[1]);
	gameplay(&mlx);
	mlx_loop(mlx->mlx_ptr);
}
