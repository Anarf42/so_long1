/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:12:06 by anruiz-d          #+#    #+#             */
/*   Updated: 2025/03/29 21:28:39 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_count_lines(t_data *data, int fd)
{
	char	*s;

	s = get_next_line(fd);
	while (s)
	{
		data->lines_count++;
		free(s);
		s = get_next_line(fd);
	}
}

int	ft_check_argument(t_data *data)
{
	size_t	len;

	len = ft_strlen(data->map_path);
	if (!ft_strncmp(&data->map_path[len - 4], ".ber", 4))
		return (0);
	return (1);
}

int	ft_set_map(t_data *data)
{
	int	fd;
	int	i;

	data->n_moves = 0;
	data->lines_count = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd == -1 || !ft_check_argument(data))
	{
		ft_printf("Bad extension, would be -> .ber");
		return (0);
	}
	ft_count_lines(data, fd);
	data->map = malloc(sizeof(char *) * (data->lines_count));
	if (!data->map)
		return (0);
	close(fd);
	i = 0;
	fd = open(data->map_path, O_RDONLY);
	while (i++ < data->lines_count && data->map)
		data->map[i] = get_next_line(fd);
	close(fd);
	if (data->map)
		data->chars_count = ft_strlen(data->map[i - 1]);
	return (1);
}