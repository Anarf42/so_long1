/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:23:05 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/06 18:53:23 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_simple_error("Error\nThe number of arguments is incorrect!");
	data = malloc(sizeof(t_data));
	if (!data)
		ft_simple_error("Error\nMemory allocation failed!");
	init_variables(data);
	init_images_structure(data);
	data->map_path = argv[1];
	if (!ft_set_map(data) || !validate_map(data))
		ft_error_and_free(data, "\nError\nMap path or structure isn't valid!");
	data->mlx = mlx_init((data->chars_count * BLOCK_SIZE),
			(data->lines_count * BLOCK_SIZE), "so_long", true);
	if (!data->mlx)
		ft_error_and_free_mlx(data, "Error at init mlx" );
	data->mlx_window = mlx_new_image(data->mlx,
			(data->chars_count * BLOCK_SIZE), (data->lines_count * BLOCK_SIZE));
	mlx_key_hook(data->mlx, &ft_hook, data);
	load_images(data);
	ft_draw_map(data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	exit (0);
}
