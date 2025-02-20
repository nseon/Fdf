/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:13 by nseon             #+#    #+#             */
/*   Updated: 2025/02/20 19:13:58 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "struct.h"
#include "draw.h"
#include <fcntl.h>
#include "parsing.h"
#include "ft_printf.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include "zoom.h"

int	move_mouse(int x, int y, t_data *data)
{
	if (data->click)
	{
		mlx_destroy_image(data->link, data->img);
		if (x > data->mouse_x)
			data->shift_x += x - data->mouse_x;
		if (x < data->mouse_x)
			data->shift_x -= data->mouse_x - x;
		if (y > data->mouse_y)
			data->shift_y += y - data->mouse_y;
		if (y < data->mouse_y)
			data->shift_y -= data->mouse_y - y;
		data->mouse_x = x;
		data->mouse_y = y;
		print_map(data);
	}
	return (0);
}


int	close_window(t_data *data)
{
	mlx_loop_end(data->link);
	return (0);
}

int	click(int keycode, int x, int y, t_data *data)
{
	if (keycode == 1)
	{
		data->mouse_x = x;
		data->mouse_y = y;
		if (keycode == 1)
			data->click = 1;
	}
	if (keycode == 4)
	{
		mlx_destroy_image(data->link, data->img);
		data->z += 0.1;
		print_map(data);
	}
	if (keycode == 5)
	{
		mlx_destroy_image(data->link, data->img);
		data->z -= 0.1;
		print_map(data);
	}
	return (0);
}

int	unclick(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		data->click = 0;
	return (0);
}

int	redirect_signals(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == 0)
		close_window(data);
	if (keycode == 65451)
	{
		mlx_destroy_image(data->link, data->img);
		if (data->lod > data->size_line - 1)
			data->lod += 1;
		print_map(data);
	}
	if (keycode == 65453)
	{
		mlx_destroy_image(data->link, data->img);
		if (data->lod >= 2)
			data->lod -= 1;
		print_map(data);
	}
	return (0);
}

void	free_all(t_data *data)
{
	mlx_destroy_image(data->link, data->img);
	mlx_destroy_window(data->link, data->window);
	mlx_destroy_display(data->link);
	free(data->link);
	free(data->pts);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;

	if (argc == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		fd = open(argv[1], O_RDONLY);
		map(fd, &data);
		if (fill_link(&data))
			return (close_window(&data));
		mlx_hook(data.window, KeyPress, KeyPressMask, &redirect_signals, &data);
		mlx_hook(data.window, MotionNotify, PointerMotionMask, &move_mouse, &data);
		mlx_hook(data.window, ButtonPress, ButtonPressMask, &click, &data);
		mlx_hook(data.window, ButtonRelease, ButtonReleaseMask, &unclick, &data);
		spacing(&data);
		print_map(&data);
		mlx_loop(data.link);
		free_all(&data);
	}
	return (0);
}
