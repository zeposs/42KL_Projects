/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:22:55 by zernest           #+#    #+#             */
/*   Updated: 2024/11/13 21:05:21 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"
// # include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define SIZE 50
# define TILE_SIZE 48
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define WKEY 119
# define AKEY 97
# define SKEY 115
# define DKEY 100

# define P_PATH "assets/objects/mako.xpm"
# define W_PATH "assets/objects/tree.xpm"
# define BG_PATH "assets/objects/grass.xpm"

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					win_x;
	int					win_y;
	int					ex_state;
	struct s_map		*map_data;
	struct s_sprites	*sprites;
}	t_mlx;

typedef struct s_map
{
	int				player_count;
	int				item_count;
	int				collected;
	int				exit_count;
	int				enemy_count;
	char			**map;
}	t_map;

typedef struct s_sprites
{
	void			*wall;
	void			*floor;
	void			*item;
	void			*exit_open;
	void			*exit_close;
	void			*player;
	void			*enemy;	
}	t_sprites;

// LOADING WINDOW WITH SPRITES

void	img_to_win(t_mlx *mlx, char	**map, int e_state);
void	render(t_mlx *mlx, void *img, int wid, int hgt);

// INITIALIZING STUFF

void	init_sprites(t_mlx **mlx);
void	load_sprites(t_mlx *mlx, t_sprites **sprites);
char	**read_map(char *map, int size_y);


// ERROR HANDLING

void	exit_perr_string(t_mlx **mlx, char *msg)
void	ft_putstr_err(char *s);
void	exit_err_str(char *str);


#endif