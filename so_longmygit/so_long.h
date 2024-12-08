/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:22:55 by zernest           #+#    #+#             */
/*   Updated: 2024/12/05 00:07:35 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"
//# include "libft/gnl/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define SIZE 48
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
# define EXIT_OPEN 2
# define WIN 3

# define P_PATH "assets/objects/mako.xpm"
# define W_PATH "assets/objects/tree.xpm"
# define BG_PATH "assets/objects/grass.xpm"
# define EXIT_OPEN_PATH "assets/objects/minecraft_bed.xpm"
# define EXIT_CLOSE_PATH "assets/objects/sun.xpm"
# define C_PATH "assets/objects/tank.xpm"

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

void    init_mlx(int ac, char **av, t_mlx **mlx);
void	init_sprites(t_mlx **mlx);
void	load_sprites(t_mlx *mlx, t_sprites **sprites);
char	**read_map(char *map, int size_y);
void	init_map(t_mlx **mlx, char *map);
void	map_data(t_mlx **mlx, char *map, int size_y);


// ERROR HANDLING

void	exit_perr_string(t_mlx **mlx, char *msg);
void	ft_putstr_err(char *s);
void	exit_err_str(char *str);

// MAP CHECKS

int		calc_col(char **map, int size_y);
int		calc_row(char *map);
int		map_check(t_mlx **mlx, int size_y);
int		is_surrounded(int row, int size_y, char *i);
int		count_elements(t_map *map_data, int row, int size_y, char *i);
int		check_element_count(t_map *map_data);

// MOVEMENT

int		movement_check(char **map, int row, int col);
int		remaining_c(char **map);
void	find_player(t_mlx *mlx, int **player_loc);

#endif