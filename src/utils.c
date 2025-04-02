/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:42 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/01 21:38:47 by anruiz-d         ###   ########.fr       */
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
	data->images->tex_character   = NULL;
    data->images->tex_collectible = NULL;
    data->images->tex_floor       = NULL;
    data->images->tex_wall        = NULL;
    data->images->tex_exit        = NULL;
    // Inicializar punteros de imágenes a NULL
    data->images->img_character   = NULL;
    data->images->img_collectible = NULL;
    data->images->img_floor       = NULL;
    data->images->img_wall        = NULL;
    data->images->img_exit        = NULL;
}