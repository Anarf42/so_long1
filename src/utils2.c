/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:05:07 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/07 19:33:17 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_simple_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (255);
}

void	ft_error_and_free(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	if (data->map)
		ft_free(data->map, data->lines_count);
	if (data->images)
		free(data->images);
	if (data)
		free(data);
	exit (255);
}

void	ft_error_and_free_mlx(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	free(data);
	exit (255);
}
