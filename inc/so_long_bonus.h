/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:35:13 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:43:35 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_W 9
# define IMG_H 18
# define BUFFER_MAX 112048

typedef struct s_map
{
	int				total_char;
	int				width;
	int				height;
	int				rectangle;
}					t_map;

typedef struct s_collec
{
	mlx_image_t		*collec;
	int				pos_x;
	int				pos_y;
}					t_collec;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*player_left_t;
	mlx_texture_t	*collec_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*empty_t;
	mlx_texture_t	*player_blink_t;
	mlx_texture_t	*player_blink_left_t;
	mlx_texture_t	*back_t;
	mlx_texture_t	*back_small_t;
	mlx_texture_t	*enemy_t;
	mlx_texture_t	*enemy1_t;
	mlx_texture_t	*enemy2_t;
	mlx_texture_t	*enemy3_t;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*player_left;
	mlx_image_t		*exit;
	mlx_image_t		*empty;
	mlx_image_t		*player_blink;
	mlx_image_t		*player_blink_left;
	mlx_image_t		*back;
	mlx_image_t		*back_small;
	mlx_image_t		*counter_back;
	mlx_image_t		*enemy;
	mlx_image_t		*enemy1;
	mlx_image_t		*enemy2;
	mlx_image_t		*enemy3;
	t_collec		*collec;
	char			**grid;
	int				width;
	int				height;
	int				e;
	int				p;
	int				c;
	int				x;
	int				collectibles;
	int				p_pos_y;
	int				p_pos_x;
	int				e_pos_y;
	int				e_pos_x;
	int				flood_c;
	int				flood_e;
	int				count;
	int				side;
	double			x_time;
	double			spin_period;
	int				spin_index;
	int				sprite_n;
	int				inst0;
	int				inst1;
	double			blink_period;
	int				blink_enabled;
	double			p_time;
}					t_game;

void				panic_cleanup(t_game *game);
void				cleanup(t_game *game);
void				final_cleanup(t_game *game);
void				error_function(int i);
void				move_player(t_game *game, int new_y, int new_x);
void				key_hook(mlx_key_data_t keydata, void *param);
void				render_map(t_game *game, t_map *map);
void				animations(void *param);
void				player_rendering(t_game *game, int x, int y);
void				enemy_rendering(t_game *game, int x, int y);
int					map_check(char *filename);
void				count_epc(t_game *game, char *buf);
int					get_height(char *buf);
int					check_epc(char *buf);
int					validate(char *buf);
int					game_start(t_map *map, char *buf);
void				move_player(t_game *game, int new_y, int new_x);
void				path_finder(t_game *game);
void				left_rendering(t_game *game);
void				collectible_rendering(t_game *game);
void				delete_images(t_game *game);

#endif
