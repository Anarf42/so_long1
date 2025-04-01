/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:15 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/01 00:23:28 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_img(t_data *data, char c, int i, int j)
{
	char	*file;
	mlx_texture_t	*tex;
	mlx_image_t		*img;
	int		h;
	int		w;

	//printf("el caracter a comparar es %c\n->", c);
	file = NULL;
	if (c == 'P')
	{
		//printf("el png del personaje es %s\n", CARACTER);
		file = CARACTER;
	}
	else if (c == 'C')
	{
		//printf("el png del tesores?%s\n", COLLECTIONABLE);
		file = COLLECTIONABLE;
	}
	else if (c == '0')
	{
		//printf("el png del fondo es?%s\n", BACKGROUND);
		file = BACKGROUND;
	}
	else if (c == '1')
	{
		//printf("el png del muro es?%s\n", WALL);
		file = WALL;
	}
	else
	{
		//printf("ha encontrado la salida?%s\n", file);
		file = EXIT_TEXTURE;
	}
	h = BLOCK_SIZE * i;
	w = BLOCK_SIZE * j;
	tex = mlx_load_png(file);
	if (!tex)
	{
		//printf("error al cargar imagen: %s\n", file);
		return;
	}
	// Convertir la textura a imagen
	img = mlx_texture_to_image(data->mlx, tex);
	// Liberar la textura si ya no la necesitas
	mlx_delete_texture(tex);
	if (!img)
	{
		printf("error al convertir textura a imagen: %s\n", file);
		return;
	}
	mlx_image_to_window(data->mlx, img, w, h);
	// Nota: No elimines la imagen inmediatamente, ya que la ventana la usará para dibujar.
}

void	ft_draw_map(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
			ft_draw_img(data, map[i][j], i, j);
	}
}