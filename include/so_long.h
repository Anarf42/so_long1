/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:39:11 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/04 15:53:43 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/include/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

# define BLOCK_SIZE		50
# define MAX_ROW		8
# define MAX_COL		15
# define CARACTER		"textures/fox.png"
# define COLLECTIONABLE	"textures/collectionable.png"
# define BACKGROUND		"textures/1.png"
# define WALL			"textures/arbusto.png"
# define EXIT_TEXTURE	"textures/exit.png"

typedef struct s_images
{
	mlx_texture_t *tex_character;
    mlx_texture_t *tex_collectible;
    mlx_texture_t *tex_floor;
    mlx_texture_t *tex_wall;
    mlx_texture_t *tex_exit;
    mlx_image_t   *img_character;
    mlx_image_t   *img_collectible;
    mlx_image_t   *img_floor;
    mlx_image_t   *img_wall;
    mlx_image_t   *img_exit;
}			t_images;

typedef struct s_data
{
	char	**map;
	int		move_count;
	int		lines_count;
	int		chars_count;
	int		p_x;
	int		p_y;
	int		n_coins;
	int		n_moves;
	void	*mlx;
	void	*mlx_window;
	char	*map_path;
	t_images	*images;
}			t_data;

int		ft_set_map(t_data *data);
int		validate_map(t_data *data);
void	ft_draw_map(t_data *data);
void	init_variables(t_data *data);
void	init_images_structure(t_data *data);
void	ft_hook(mlx_key_data_t	key_data, void *param);
void	load_images(t_data *data);
int		ft_is_accesible(t_data *data);
void	ft_aux_load_images(t_data *data);
void    ft_show_image(t_data *data, mlx_image_t *img, int j, int i);
#endif