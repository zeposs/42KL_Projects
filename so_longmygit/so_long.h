/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:22:55 by zernest           #+#    #+#             */
/*   Updated: 2024/12/16 22:06:48 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libftv2/ft_printf/ft_printf.h"
# include "libftv2/gnl/get_next_line.h"
# include "libftv2/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifdef __APPLE__
#  define KEY_ESC 0x35
#  define KEY_W 0x0D
#  define KEY_UP 0x7E
#  define KEY_A 0x00
#  define KEY_LEFT 0x7B
#  define KEY_S 0x01
#  define KEY_DOWN 0x7D
#  define KEY_D 0x02
#  define KEY_RIGHT 0x7C
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_UP 65362
#  define KEY_A 97
#  define KEY_LEFT 65361
#  define KEY_S 115
#  define KEY_DOWN 65364
#  define KEY_D 100
#  define KEY_RIGHT 65363
# endif

# define SIZE 48
# define TILE_SIZE 48
# define UP 130
# define DOWN 140
# define LEFT 110
# define RIGHT 120
# define ESC 65307
# define WKEY 119
# define AKEY 97
# define SKEY 115
# define DKEY 100
# define EXIT_OPEN 2
# define WIN 3

# define P_PATH "assets/objects/mako.xpm"
# define W_PATH "assets/objects/sun.xpm"
# define BG_PATH "assets/objects/grass.xpm"
# define EXIT_OPEN_PATH "assets/objects/minecraft_bed.xpm"
# define EXIT_CLOS_PATH "assets/objects/cross.xpm"
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
}						t_mlx;

typedef struct s_map
{
	int					player_count;
	int					item_count;
	int					collected;
	int					exit_count;
	int					enemy_count;
	char				**map;
}						t_map;

typedef struct s_sprites
{
	void				*wall;
	void				*floor;
	void				*item;
	void				*exit_open;
	void				*exit_close;
	void				*player;
	void				*enemy;
}						t_sprites;

// LOADING WINDOW WITH SPRITES

void					img_to_win(t_mlx *mlx, char **map, int e_state);
void					render(t_mlx *mlx, void *img, int wid, int hgt);

// INITIALIZING STUFF

void					init_mlx(int ac, char **av, t_mlx **mlx);
void					init_sprites(t_mlx **mlx);
void					load_sprites(t_mlx *mlx, t_sprites **sprites);
char					**read_map(char *map, int size_y);
void					init_map(t_mlx **mlx, char *map);
void					map_data(t_mlx **mlx, char *map, int size_y);
void					init_win(t_mlx **mlx);
void					init_key(t_mlx **mlx);
void					gameplay(t_mlx **mlx);

// ERROR HANDLING (quit game is in here too)

void					exit_perr_string(t_mlx **mlx, char *msg);
void					ft_putstr_err(char *s);
void					exit_err_str(t_mlx **mlx, char *str);
void					free_data(char ***map, int **player_loc);
void					free_mlx(t_mlx **mlx);
void					quit_game(t_mlx *mlx, int action);
void					ft_putstr_err_exit(char *s);

// MAP CHECKS

int						calc_col(char **map, int size_y);
int						calc_row(char *map);
int						map_check(t_mlx **mlx, int size_y);
int						is_surrounded(int row, int size_y, char *i);
int						count_elements(t_map *map_data, int row, int size_y,
							char *i);
int						check_element_count(t_map *map_data);
char					**dup_map(t_mlx *mlx);
void					flood_fill(t_mlx **mlx);
void					fill(t_mlx **mlx, char ***map_dup, int row, int col);

// MOVEMENT (escape functions is in here as well)

int						movement_check(char **map, int row, int col);
int						remaining_c(char **map);
void					find_player(t_mlx *mlx, int **player_loc);
int						check_movement_validity(t_mlx *mlx, int **player_loc,
							char **map_dup, int dir);
void					move_up(t_mlx *mlx, int **player_loc, int *move_count);
void					move_down(t_mlx *mlx, int **player_loc,
							int *move_count);
void					move_left(t_mlx *mlx, int **player_loc,
							int *move_count);
void					move_right(t_mlx *mlx, int **player_loc,
							int *move_count);
int						escape(t_mlx *mlx);
void					escape_key(t_mlx *mlx, int keycode, int **player_loc);
int						controls(int key, t_mlx *mlx);
void					step_counter(t_mlx *mlx, int step_count);

#endif