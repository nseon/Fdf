/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:41 by nseon             #+#    #+#             */
/*   Updated: 2025/02/18 16:04:50 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "draw.h"
#include "mlx.h"
#include "parsing.h"
#include "libft.h"
#include "ft_printf.h"

int	grid(t_data *data, t_img img)
{
	int				x;
	int				y;
	const double	rad = 120 * M_PI / 180;

	y = -1;
	while (++y < data->nb_line)
	{
		x = -1;
		while (++x < data->size_line)
		{
			data->pts[y * data->size_line + x].x = data->pts[y
				* data->size_line + x].x + data->pts[y * data->size_line + x].y
				* cos(rad) + data->pts[y * data->size_line + x].z * cos(-rad);
			data->pts[y * data->size_line + x].y = data->pts[y * data->size_line
				+ x].y * sin(rad) + data->pts[y * data->size_line + x].z
				* sin(-rad);
			if (x)
				draw_line(data->pts[y * data->size_line + x],
					data->pts[y * data->size_line + x - 1], img);
			if (y)
				draw_line(data->pts[y * data->size_line + x],
					data->pts[(y - 1) * data->size_line + x], img);
		}
	}
	return (0);
}

void	print_map(t_data *data)
{
	t_img	img;

	data->img = mlx_new_image(data->link, WIDTH, HEIGHT);
	if (!data->img)
		close_window(0, data);
	ft_bzero(&img, sizeof(t_img));
	img.pxls = mlx_get_data_addr(data->img, &img.bits, &img.len, &img.endian);
	if (grid(data, img))
		close_window(0, data);
	mlx_put_image_to_window(data->link, data->window, data->img, 0, 0);
}
