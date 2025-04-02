/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:15 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/02 14:58:31 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_data *data)
{
    data->images->tex_character = mlx_load_png(CARACTER);
    data->images->tex_collectible = mlx_load_png(COLLECTIONABLE);
    data->images->tex_floor = mlx_load_png(BACKGROUND);
    data->images->tex_wall = mlx_load_png(WALL);
    data->images->tex_exit = mlx_load_png(EXIT_TEXTURE);
    if (data->images->tex_character)
        data->images->img_character = mlx_texture_to_image(data->mlx, data->images->tex_character);
    if (data->images->tex_collectible)
        data->images->img_collectible = mlx_texture_to_image(data->mlx, data->images->tex_collectible);
    if (data->images->tex_floor)
        data->images->img_floor = mlx_texture_to_image(data->mlx, data->images->tex_floor);
    if (data->images->tex_wall)
        data->images->img_wall = mlx_texture_to_image(data->mlx, data->images->tex_wall);
    if (data->images->tex_exit)
        data->images->img_exit = mlx_texture_to_image(data->mlx, data->images->tex_exit);
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


void    ft_draw_background(t_data *data)
{
    //char    **map;
    int     i;
    int     j;
    mlx_image_t *img;
    
    img = data->images->img_floor;
    i = -1;
    while (++i < data->lines_count)
    {
        j = -1;
        while (++j < data->chars_count)
        {
            if (img)
            {
                mlx_resize_image(img, BLOCK_SIZE, BLOCK_SIZE);
                mlx_image_to_window(data->mlx, img, BLOCK_SIZE * j, BLOCK_SIZE * i);
            }
        }
    }
}

void    ft_draw_surface(t_data *data)
{
    int			i;
    int			j;
    mlx_image_t *img;

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
				{
					mlx_resize_image(img, BLOCK_SIZE, BLOCK_SIZE);
					mlx_image_to_window(data->mlx, img, (BLOCK_SIZE * j), (BLOCK_SIZE * i));
				}
			}
	}
}
void ft_draw_player(t_data *data)
{
    int x;
	int	y;
    int player_size;  // Ajusta este factor según lo deseado
    int offset;
    mlx_image_t *img;

    // data->p_x y data->p_y deben estar actualizados a la posición actual del jugador
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
/*
void ft_draw_img(t_data *data, char c, int i, int j)
{
    mlx_image_t *img;
    int h, w;

    if (c == 'P')
    {
        img = data->images->img_floor;
        h = BLOCK_SIZE * i;
        w = BLOCK_SIZE * j;
        if (img)
            mlx_resize_image(img, BLOCK_SIZE, BLOCK_SIZE);
        mlx_image_to_window(data->mlx, img, w, h);
        img = data->images->img_character;
        int x, y;
        int player_size = (int)(BLOCK_SIZE * 0.5); // Tamaño del jugador (ajusta según lo que necesites)
        int offset = (BLOCK_SIZE - player_size) / 2;
        x = BLOCK_SIZE * data->p_x;
        y = BLOCK_SIZE * data->p_y;
        mlx_resize_image(img, player_size, player_size);
        mlx_image_to_window(data->mlx, img, x + offset, y + offset);
    }
    else
    {
        if (c == 'C')
            img = data->images->img_collectible;
        else if (c == '0')
            img = data->images->img_floor;
        else if (c == '1')
            img = data->images->img_wall;
        else
            img = data->images->img_exit;
        h = BLOCK_SIZE * i;
        w = BLOCK_SIZE * j;
        if (img)
            mlx_resize_image(img, BLOCK_SIZE, BLOCK_SIZE);
        mlx_image_to_window(data->mlx, img, w, h);
    }
}

*/
void	ft_draw_map(t_data *data)
{
// Primero dibujamos el fondo en todas las celdas
    ft_draw_background(data);
    // Luego dibujamos los elementos fijos (muros, coleccionables, salida)
    ft_draw_surface(data);
    // Finalmente, dibujamos al jugador en su posición actual
    ft_draw_player(data);
}
