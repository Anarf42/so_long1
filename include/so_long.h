/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:39:11 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/30 21:28:14 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define BLOCK_SIZE		40
# define CARACTER		"textures/caracter.png"
# define COLLECTIONABLE	"textures/collectionable.png"
# define BACKGROUND		"textures/background.png"
# define WALL			"textures/wall.png"
# define EXIT_TEXTURE	"textures/exit.png"

# define KEY_ESC		256
# define KEY_DOWN		83
# define KEY_UP			87
# define KEY_LEFT		65
# define KEY_RIGHT		68

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