/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:22:26 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/07 19:29:02 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy(t_data *data)
{
	mlx_terminate(data->mlx);
	exit(0);
}

void	ft_move_player(t_data *data, int keycode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (keycode == MLX_KEY_W)
		i = -1;
	if (keycode == MLX_KEY_S)
		i = 1;
	if (keycode == MLX_KEY_A)
		j = -1;
	if (keycode == MLX_KEY_D)
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
	if (keycode == MLX_KEY_D)
	{
		if (data->map[data->p_y][data->p_x + 1] == '1'
		|| (data->map[data->p_y][data->p_x + 1] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == MLX_KEY_A)
	{
		if (data->map[data->p_y][data->p_x - 1] == '1'
		|| (data->map[data->p_y][data->p_x - 1] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == MLX_KEY_W)
	{
		if (data->map[data->p_y - 1][data->p_x] == '1'
		|| (data->map[data->p_y - 1][data->p_x] == 'E' && data->n_coins > 0))
			return (0);
	}
	if (keycode == MLX_KEY_S)
	{
		if (data->map[data->p_y + 1][data->p_x] == '1'
		|| (data->map[data->p_y + 1][data->p_x] == 'E' && data->n_coins > 0))
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
	t_data	*data;
	int		keycode;

	data = (t_data *)param;
	keycode = key_data.key;
	if (key_data.action != MLX_PRESS)
		return ;
	if (keycode == MLX_KEY_ESCAPE)
	{
		mlx_terminate(data->mlx);
		exit(1);
	}
	if (keycode == MLX_KEY_S)
		ft_move_hook(keycode, data);
	if (keycode == MLX_KEY_A)
		ft_move_hook(keycode, data);
	if (keycode == MLX_KEY_D)
		ft_move_hook(keycode, data);
	if (keycode == MLX_KEY_W)
		ft_move_hook(keycode, data);
}
