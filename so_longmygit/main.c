/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:31:14 by zernest           #+#    #+#             */
/*   Updated: 2024/11/11 19:23:51 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{

	t_data data;

	int width = 1920;
	int height = 1080;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "Girls Und Panzer");
	data.textures[0] = mlx_xpm_file_to_image(data.mlx_ptr, "assets/mako.xpm", &width, &height);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0], 0, 0);
	mlx_loop(data.mlx_ptr);

//	player =  mlx_xpm_file_to_image
}