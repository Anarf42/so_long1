/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:15 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/07 22:45:05 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_data *data)
{
	if ((open(CARACTER, O_RDONLY) == -1) || (open(WALL, O_RDONLY) == -1)
		|| (open(COLLECTIONABLE, O_RDONLY) == -1)
		|| (open(BACKGROUND, O_RDONLY) == -1)
		|| (open(EXIT_TEXTURE, O_RDONLY) == -1))
	{
		perror("Texturas");
		mlx_terminate(data->mlx);
		ft_error_and_free(data, "error, falta imagen o fallan permisos");
	}
	data->images->tex_character = mlx_load_png(CARACTER);
	data->images->tex_collectible = mlx_load_png(COLLECTIONABLE);
	data->images->tex_floor = mlx_load_png(BACKGROUND);
	data->images->tex_wall = mlx_load_png(WALL);
	data->images->tex_exit = mlx_load_png(EXIT_TEXTURE);
	if (!data->images->tex_character || !data->images->tex_collectible
		|| !data->images->tex_floor || !data->images->tex_wall
		|| !data->images->tex_exit)
	{
		mlx_terminate(data->mlx);
		ft_error_and_free(data, "error, falta imagen o fallan permisos");
	}
	ft_aux_load_images(data);
}

void	ft_draw_background(t_data *data)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	img = data->images->img_floor;
	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (img)
				ft_show_image(data, img, BLOCK_SIZE * j, BLOCK_SIZE * i);
		}
	}
}

void	ft_draw_surface(t_data *data)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (data->map[i][j] == 'C')
				img = data->images->img_collectible;
			else if (data->map[i][j] == '1')
				img = data->images->img_wall;
			else if (data->map[i][j] == 'E')
				img = data->images->img_exit;
			else
				continue ;
			if (img)
				ft_show_image(data, img, BLOCK_SIZE * j, BLOCK_SIZE * i);
		}
	}
}

void	ft_draw_player(t_data *data)
{
	int			x;
	int			y;
	int			player_size;
	int			offset;
	mlx_image_t	*img;

	x = BLOCK_SIZE * data->p_x;
	y = BLOCK_SIZE * data->p_y;
	player_size = (int)(BLOCK_SIZE * 0.75);
	offset = (BLOCK_SIZE - player_size) / 2;
	img = data->images->img_character;
	if (img)
	{
		mlx_resize_image(img, player_size, player_size);
		mlx_image_to_window(data->mlx, img, x + offset, y + offset);
	}
}

void	ft_draw_map(t_data *data)
{
	ft_draw_background(data);
	ft_draw_surface(data);
	ft_draw_player(data);
}
