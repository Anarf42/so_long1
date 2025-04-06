/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:20:32 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/06 18:15:37 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_data *data, char **copy_map, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->lines_count || y >= data->chars_count)
		return ;
	if (copy_map[x][y] == '1' || copy_map[x][y] == 'X')
		return ;
	copy_map[x][y] = 'X';
	flood_fill(data, copy_map, x + 1, y);
	flood_fill(data, copy_map, x - 1, y);
	flood_fill(data, copy_map, x, y + 1);
	flood_fill(data, copy_map, x, y - 1);
}

static	int	ft_aux_is_accesible(t_data *data, char **copy_map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->lines_count)
	{
		j = -1;
		while (++j < data->chars_count)
		{
			if (copy_map[i][j] != 'X' && copy_map[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	ft_is_accesible(t_data *data)
{
	char	**copy_map;
	int		i;

	copy_map = malloc(sizeof(char *) * (data->lines_count + 1));
	if (!copy_map)
		return (0);
	i = -1;
	while (++i < data->lines_count)
		copy_map[i] = ft_strdup(data->map[i]);
	if (!copy_map)
	{
		while (i-- > 0)
			free(copy_map[i]);
		return (free(copy_map), 0);
	}
	copy_map[i] = NULL;
	flood_fill(data, copy_map, data->p_y, data->p_x);
	if (!ft_aux_is_accesible(data, copy_map))
		return (0);
	return (free(copy_map), 1);
}
