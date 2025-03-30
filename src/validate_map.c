/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 21:31:45 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/30 20:19:52 by anruiz-d         ###   ########.fr       */
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
	data->n_coins = 0;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (data->map[i][j] != 'C' && data->map[i][j] != 'P'
				&& data->map[i][j] != 'E' && data->map[i][j] != '0'
				&& data->map[i][j] != '1')
				{
					printf("el caracter que da error es %c\n", data->map[i][j]);
					ft_printf("Error_0");
					return (0);
				}
				if (data->map[i][j] == 'C')
					data->n_coins++;
				if (data->map [i][j] == 'E')
					n_exit++;
		}
	}
	if (data->n_coins < 1 || n_exit != 1)
	{
		ft_printf("Error_1");
		return (0);
	}
	return (1);
}

int	ft_check_map_shape(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->lines_count - 1)
	{
		if (data->chars_count != (int)ft_strlen(data->map[i]) - 1)
		{
			ft_printf("Error_2");
			return (0);
		}
		i++;
	}
	if (data->chars_count != (int)ft_strlen(data->map[data->lines_count - 1]))
	{
		ft_printf("Error_3");
		return (0);
	}
	return (1);
}

int	ft_check_border(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	//printf("numero de lineas es -> %d\n", data->lines_count);
	while (++i < data->lines_count)
	{
		j = -1;
		if (i == 0 || i == data->lines_count - 1)
		{
			//printf("numero de caracteres es -> %d\n", data->chars_count);
			while (++j < data->chars_count)
			{
				//printf("El valor de la posicion en i %d y en j %d es de -> %c\n",i, j, data->map[i][j]);
				if (data->map[i][j] != '1')
				{
					ft_printf("Error_4");
					return (0);
				}
			}
		}
		
		if (data->map[i][0] != '1')
		{
			//printf("la posicion en i es de -> %d\n", i);
			//printf("la posicion en el mapa es de ->%d\n", data->map[i][0]);
			ft_printf("Error_5");
			return (0);
		}
		if (data->map[i][data->chars_count - 1] != '1')
		{
			ft_printf("Error_6");
			return (0);
		}
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
	{
		ft_printf("Error_7");
		return (0);
	}
}

int	validate_map(t_data *data)
{
	if (!validate_map_player(data) || !ft_check_border(data)
		|| !ft_check_map_shape(data) || !ft_check_map_values(data))
		return (0);
	return (1);
}