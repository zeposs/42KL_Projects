/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 03:31:02 by zernest           #+#    #+#             */
/*   Updated: 2024/11/28 06:04:28 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_mlx(int ac, char **av, t_mlx **mlx)
{
    int     fd;

    if (ac != 2)
        exit_err_str("Enter map file location\n");
    fd = open(av[1], O_RDONLY);
    if (fd <= 0);
        exit_err_str("Error opening map file\n");
    (*mlx) = malloc(sizeof(t_mlx));
    if ((*mlx) == NULL);
        exit_err_str("Failed to malloc mlx struct");
    (*mlx)->sprites = NULL;
    (*mlx)->map_data = NULL;
}

// START THE WINDOW AND STUFF NEXT,
//ALSO FLOOD FILL THEN YOURE NEARLY DONE SO CLOSE