/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:13 by nseon             #+#    #+#             */
/*   Updated: 2025/02/12 16:57:55 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/keysym.h>
#include "libft.h"
#include "struct.h"
#include "draw.h"
#include <fcntl.h>
#include "parsing.h"
#include "ft_printf.h"
#include "zoom.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(data->link);
		mlx_destroy_window(data->link, data->window);
		mlx_destroy_display(data->link);
		free(data->link);
		free(data->pts);
		exit(EXIT_SUCCESS);
	}
	return (0);
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
		data.link = mlx_init();
		if (!data.link)
			return (-1);
		data.window = mlx_new_window(data.link, WIDTH, HEIGHT, "FDF");
		if (!data.window)
		{
			mlx_destroy_display(data.link);
			return (-1);
		}
		mlx_key_hook(data.window, &close_window, &data);
		spacing(&data);
		print_map(&data);
		mlx_loop(data.link);
	}
	return (0);
}
