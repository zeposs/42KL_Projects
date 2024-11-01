/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:14 by zernest           #+#    #+#             */
/*   Updated: 2024/11/01 17:48:48 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	main(void)
{

	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Girls Und Panzer");
	data.texture[0] = mlx_xpm_file_to_image(data.mlx_ptr, /assets/mako.xpm, 1920, 1080);
	mlx_loop(data.mlx_ptr);

//	player =  mlx_xpm_file_to_image
}