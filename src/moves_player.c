/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:22:26 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/30 15:10:57 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy(t_data *data)
{
	mlx_delete_image(data->mlx, data->mlx_window);
	exit(0);
}

void	ft_move_player(t_data *data, int keycode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (keycode ==KEY_UP)
		i = -1;
	if (keycode == KEY_DOWN)
		i = 1;
	if (keycode == KEY_LEFT)
		j = -1;
	if (keycode == KEY_RIGHT)
		j = 1;
	data->map[data->p_y][data->p_x] = '0';
	data->p_y += i;
	data->p_x += j;
	if (data->map[data->p_y][data->p_x] == 'C')
		data->n_coins--;
	if (data->map[data->p_y][data->p_x] == 'E')
	{
		if (data->n_coins == 0)
			ft_destroy(data);
	}
	data->map[data->p_y][data->p_x] = 'P';
	ft_draw_map(data);
}

int	ft_can_move(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
	{
		if (data->map[data->p_y][data->p_x + 1] == '1'
		|| (data->map[data->p_y][data->p_x + 1] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == KEY_LEFT)
	{
		if (data->map[data->p_y][data->p_x - 1] == '1'
		|| (data->map[data->p_y][data->p_x - 1] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == KEY_UP)
	{
		if (data->map[data->p_y + 1][data->p_x] == '1'
		|| (data->map[data->p_y + 1][data->p_x == 'E'] && data->n_coins > 0))
			return (0);
	}
	if (keycode == KEY_DOWN)
	{
		if (data->map[data->p_y - 1][data->p_x] == '1'
		|| (data->map[data->p_y - 1][data->p_x == 'E'] && data->n_coins > 0))
			return (0);
	}
	return (1);
}

void	ft_move_hook(int keycode, t_data *data)
{
	if (ft_can_move(keycode, data) == 1)
	{
		ft_move_player(data, keycode);
		data->n_moves++;
		ft_printf("%d\n", data->n_moves);
	}
}

void	ft_hook(mlx_key_data_t	key_data, void *param)
{
	t_data *data;
    int keycode = key_data.key;

	 data = (t_data *)param;
	 keycode = key_data.key;
	if (keycode == KEY_ESC)
	{
		mlx_delete_image(data->mlx, data->mlx_window);
		exit(1);
	}
	if (keycode == KEY_DOWN)
		ft_move_hook(keycode, data);
	if (keycode == KEY_LEFT)
		ft_move_hook(keycode, data);
	if (keycode == KEY_RIGHT)
		ft_move_hook(keycode, data);
	if (keycode == KEY_UP)
		ft_move_hook(keycode, data);
}

