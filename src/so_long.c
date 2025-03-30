/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:23:05 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/30 15:31:11 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		window_width;
	int		window_height;

	if (argc != 2)
	{
		ft_printf("Error\nThe number of arguments is incorrect!");
		return (1);
	}
	data = malloc(sizeof(t_data));
    if (!data)
    {
        ft_printf("Error\nMemory allocation failed!");
        return (1);
    }
	data->map_path = argv[1];
	if (!ft_set_map(data) || !validate_map(data))
	{
		ft_printf("\nError\nMap path or structure isn't valid!");
		free(data);
		return (1);
	}
	window_height = data->lines_count * BLOCK_SIZE;
	window_width = data->chars_count * BLOCK_SIZE;
	data->mlx = mlx_init(window_width, window_height, "so_long", true);
	if (!data->mlx)
	{
		free(data);
		return (1);
	}
	data->mlx_window = mlx_new_image(data->mlx, window_width, window_height);
	ft_draw_map(data);
	mlx_key_hook(data->mlx, &ft_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	exit (0);
}
