/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 01:05:07 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/04/06 18:46:58 by anruiz-d         ###   ########.fr       */
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
	free(data);
	exit (255);
}

void	ft_error_and_free_mlx(t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	mlx_terminate(data->mlx);
	free(data);
	exit (255);
}
