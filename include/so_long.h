/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:39:11 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/30 15:18:52 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define BLOCK_SIZE		50
# define CARACTER		"textures/pikachu2.png"
# define COLLECTIONABLE	"textures/pikachu.png"
# define BACKGROUND		"textures/pikachu.png"
# define WALL			"textures/pikachu.png"
# define EXIT			"textures/pikachu.png"

# define KEY_ESC		53
# define KEY_DOWN		1
# define KEY_UP			13
# define KEY_LEFT		0
# define KEY_RIGHT		2

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
}			t_data;


int		ft_set_map(t_data *data);
int		validate_map(t_data *data);
void	ft_draw_map(t_data *data);
void	ft_hook(mlx_key_data_t	key_data, void *param);

#endif