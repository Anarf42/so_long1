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

int	ft_count_lines(t_data *data, int fd)
{
	char	*s;
	int		flag;

	s = get_next_line(fd);
	flag = 1;
	while (s)
	{
		if (s[0] == '\n' || s == NULL)
			flag = 0;
		data->lines_count++;
		free(s);
		s = get_next_line(fd);
	}
	if (flag == 0)
		data->lines_count = 0;
	return (flag);
}

int	ft_check_argument(t_data *data)
{
	size_t	len;

	len = ft_strlen(data->map_path);
	if (ft_strncmp(&data->map_path[len - 4], ".ber", 4))
		return (0);
	return (1);
}

static	int	ft_aux_set_map(t_data *data)
{
	int	i;
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (!fd)
		return (0);
	i = -1;
	while (++i < data->lines_count)
		data->map[i] = get_next_line(fd);
	data->map[i] = NULL;
	close(fd);
	return (1);
}

int	ft_set_map(t_data *data)
{
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd == -1 || !ft_check_argument(data))
		return (close(fd), 0);
	if (!ft_count_lines(data, fd))
		return (close(fd), 0);
	close(fd);
	if (data->lines_count > MAX_ROW)
		return (0);
	data->map = ft_calloc((data->lines_count + 1), sizeof(char *));
	if (!data->map)
		return (0);
	if (!ft_aux_set_map(data))
		return (0);
	if (data->map)
		data->chars_count = (int)ft_strlen(data->map[data->lines_count - 1]);
	if (data->chars_count > MAX_COL)
		return (0);
	return (1);
}
