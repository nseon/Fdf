/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:13 by nseon             #+#    #+#             */
/*   Updated: 2025/03/04 11:57:21 by nseon            ###   ########.fr       */
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
#include "signals.h"
#include "mouse.h"

int	close_window(t_data *data)
{
	mlx_loop_end(data->link);
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
		if (map(fd, &data))
			return (0);
		if (fill_link(&data))
			return (close_window(&data));
		mlx_hook(data.window, KeyPress, KeyPressMask, &redirect_signals, &data);
		mlx_hook(data.window, MotionNotify, PointerMotionMask, &move_mouse,
			&data);
		mlx_hook(data.window, ButtonPress, ButtonPressMask, &click, &data);
		mlx_hook(data.window, ButtonRelease, ButtonReleaseMask, &unclick,
			&data);
		spacing(&data);
		print_map(&data);
		mlx_loop(data.link);
		free_all(&data);
	}
	return (0);
}
