/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:13 by nseon             #+#    #+#             */
/*   Updated: 2025/02/20 13:08:46 by nseon            ###   ########.fr       */
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

int	close_window(t_data *data)
{
	mlx_loop_end(data->link);
	return (0);
}

int	redirect_signals(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == 0)
		close_window(data);
	if (keycode == XK_Up)
	{
		mlx_destroy_image(data->link, data->img);
		data->z += 0.1;
		print_map(data);
	}
	if (keycode == XK_Down)
	{
		mlx_destroy_image(data->link, data->img);
		data->z -= 0.1;
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
	int		check;

	if (argc == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		fd = open(argv[1], O_RDONLY);
		map(fd, &data);
		check = fill_link(&data);
		if (check)
			return (close_window(&data));
		mlx_hook(data.window, KeyPress, KeyPressMask, &redirect_signals, &data);
		spacing(&data);
		print_map(&data);
		mlx_loop(data.link);
		free_all(&data);
	}
	return (0);
}
