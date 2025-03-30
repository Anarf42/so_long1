/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:25:15 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/30 15:13:53 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_img(t_data *data, char c, int i, int j)
{
	char	*file;
	void	*img;
	int		h;
	int		w;

	file = NULL;
	if (c == 'P')
		file = CARACTER;
	else if (c == 'C')
		file = COLLECTIONABLE;
	else if (c == '0')
		file = BACKGROUND;
	else if (c == '1')
		file = WALL;
	else
		file = EXIT;
	h = BLOCK_SIZE * j;
	w = BLOCK_SIZE * i;
	img = mlx_load_png(file);
	mlx_image_to_window(data->mlx, img, w, h);
	mlx_delete_image(data->mlx, img);
}

void	ft_draw_map(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	i = 0;
	while (i++ < data->lines_count)
	{
		j = 0;
		while (j++ < data->chars_count)
			ft_draw_img(data, map[i][j], i, j);
	}
}