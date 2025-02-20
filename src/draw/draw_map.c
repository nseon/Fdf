/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:00:41 by nseon             #+#    #+#             */
/*   Updated: 2025/02/20 18:59:22 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "struct.h"
#include "draw.h"
#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"

t_point	pt_place(t_data *data, t_point pt)
{
	const double	rad = 120 * M_PI / 180;
	const int		x = pt.x;
	const int		y = pt.y;

	pt.x += data->zoom * x + WIDTH / 15;
	pt.y += data->zoom * y;
	pt.z *= data->z * (4 * data->size_line * (1 / ((double)data->size_line / 8))
			* (1 / (double)data->max_z));
	pt.x = pt.x + pt.y * cos(rad) + pt.z * cos(-rad);
	pt.y = pt.y * sin(rad) + pt.z * sin(-rad);
	pt.x += data->shift_x;
	pt.y += data->shift_y;
	return (pt);
}

int	grid(t_data *data, t_img img)
{
	int				x;
	int				y;

	y = 0;
	while (y < data->nb_line)
	{
		x = 0;
		while (x < data->size_line)
		{
			if (x > 0)
				draw_line(pt_place(data, data->pts[y * data->size_line + x]),
					pt_place(data, data->pts[y * data->size_line + x - data->lod]),
					img);
			if (y > 0)
				draw_line(pt_place(data, data->pts[y * data->size_line + x]),
					pt_place(data, data->pts[(y - data->lod) * data->size_line + x]),
					img);
			x += data->lod;
		}
		y += data->lod;
	}
	return (0);
}

void	print_map(t_data *data)
{
	t_img	img;

	data->img = mlx_new_image(data->link, WIDTH, HEIGHT);
	if (!data->img)
		close_window(data);
	ft_bzero(&img, sizeof(t_img));
	img.pxls = mlx_get_data_addr(data->img, &img.bits, &img.len, &img.endian);
	if (grid(data, img))
		close_window(data);
	mlx_put_image_to_window(data->link, data->window, data->img, 0, 0);
}
