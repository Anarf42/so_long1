/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:42 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/06 13:36:11 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_variables(t_data *data)
{
	data->chars_count = 0;
	data->lines_count = 0;
	data->map = NULL;
	data->map_path = NULL;
	data->mlx = NULL;
	data->mlx_window = NULL;
	data->move_count = 0;
	data->n_coins = 0;
	data->n_moves = 0;
	data->p_x = 0;
	data->p_y = 0;
}

void	init_images_structure(t_data *data)
{
	data->images = malloc(sizeof(t_images));
	if (!data->images)
		exit(255);
	data->images->tex_character = NULL;
	data->images->tex_collectible = NULL;
	data->images->tex_floor = NULL;
	data->images->tex_wall = NULL;
	data->images->tex_exit = NULL;
	data->images->img_character = NULL;
	data->images->img_collectible = NULL;
	data->images->img_floor = NULL;
	data->images->img_wall = NULL;
	data->images->img_exit = NULL;
}

void	ft_aux_delete_texture(t_data *data)
{
	if (data->images->tex_character)
		mlx_delete_texture(data->images->tex_character);
	if (data->images->tex_collectible)
		mlx_delete_texture(data->images->tex_collectible);
	if (data->images->tex_floor)
		mlx_delete_texture(data->images->tex_floor);
	if (data->images->tex_wall)
		mlx_delete_texture(data->images->tex_wall);
	if (data->images->tex_exit)
		mlx_delete_texture(data->images->tex_exit);
}

void	ft_aux_load_images(t_data *data)
{
	if (data->images->tex_character)
		data->images->img_character
			= mlx_texture_to_image(data->mlx, data->images->tex_character);
	if (data->images->tex_collectible)
		data->images->img_collectible
			= mlx_texture_to_image(data->mlx, data->images->tex_collectible);
	if (data->images->tex_floor)
		data->images->img_floor
			= mlx_texture_to_image(data->mlx, data->images->tex_floor);
	if (data->images->tex_wall)
		data->images->img_wall
			= mlx_texture_to_image(data->mlx, data->images->tex_wall);
	if (data->images->tex_exit)
		data->images->img_exit
			= mlx_texture_to_image(data->mlx, data->images->tex_exit);
	ft_aux_delete_texture(data);
}

void	ft_show_image(t_data *data, mlx_image_t *img, int j, int i)
{
	mlx_resize_image(img, BLOCK_SIZE, BLOCK_SIZE);
	mlx_image_to_window(data->mlx, img, j, i);
}
