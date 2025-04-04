/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:31:45 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/04 15:50:15 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_check_map_values(t_data *data)
{
	int	n_exit;
	int	i;
	int	j;

	i = -1;
	n_exit = 0;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (data->map[i][j] != 'C' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'E' && data->map[i][j] != '0'
				&& data->map[i][j] != '1')
				return (0);
			if (data->map[i][j] == 'C')
				data->n_coins++;
			if (data->map [i][j] == 'E')
				n_exit++;
		}
	}
	if (data->n_coins < 1 || n_exit != 1)
		return (0);
	return (1);
}

int	ft_check_map_shape(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lines_count - 1)
	{
		if (data->chars_count != (int)ft_strlen(data->map[i]) - 1)
			return (0);
		i++;
	}
	if (data->chars_count != (int)ft_strlen(data->map[data->lines_count - 1]))
		return (0);
	return (1);
}

int	ft_check_border(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		if (i == 0 || i == data->lines_count - 1)
		{
			while (++j < data->chars_count)
			{
				if (data->map[i][j] != '1')
					return (0);
			}
		}
		if (data->map[i][0] != '1')
			return (0);
		if (data->map[i][data->chars_count - 1] != '1')
			return (0);
	}
	return (1);
}

int	validate_map_player(t_data *data)
{
	int	n_player;
	int	i;
	int	j;

	n_player = 0;
	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (data->map[i][j] == 'P')
			{
				n_player++;
				data->p_x = j;
				data->p_y = i;
			}
		}
	}
	if (n_player == 1)
		return (1);
	else
		return (0);
}

int	validate_map(t_data *data)
{
	if (!validate_map_player(data) || !ft_check_border(data)
		|| !ft_check_map_shape(data) || !ft_check_map_values(data)
		|| !ft_is_accesible(data))
		return (0);
	return (1);
}
