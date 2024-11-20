/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paranha <paranha@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:35:22 by paranha           #+#    #+#             */
/*   Updated: 2024/03/25 17:07:32 by paranha          ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	mlx_texture_t	*collec_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*empty_t;
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*empty;
	t_collec		*collec;
	char			**grid;
	int				width;
	int				height;
	int				e;
	int				p;
	int				c;
	int				collectibles;
	int				p_pos_y;
	int				p_pos_x;
	int				e_pos_y;
	int				e_pos_x;
	int				flood_c;
	int				flood_e;
	int				count;
	int				side;
}					t_game;

void				panic_cleanup(t_game *game);
void				cleanup(t_game *game);
void				final_cleanup(t_game *game);
void				error_function(int i);
void				render_map(t_game *game, t_map *map);
void				key_hook(mlx_key_data_t keydata, void *param);
int					map_check(char *filename);
void				count_epc(t_game *game, char *buf);
int					validate(char *buf);
int					check_epc(char *buf);
int					get_height(char *buf);
int					game_start(t_map *map, char *buf);
void				render_map(t_game *game, t_map *map);
void				path_finder(t_game *game);
void				move_player(t_game *game, int new_y, int new_x);

#endif
