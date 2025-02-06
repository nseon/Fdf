/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:13 by nseon             #+#    #+#             */
/*   Updated: 2025/02/06 16:43:59 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <X11/keysym.h>
#include "libft.h"
#include "struct.h"
#include "draw.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(data->link);
		mlx_destroy_window(data->link, data->window);
		mlx_destroy_display(data->link);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(void)
{
	t_data	data;
	t_point	pt0;
	t_point	pt1;

	pt0.x = 0;
	pt0.y = 0;
	pt1.x = 1920;
	pt1.y = 1080;
	data.link = mlx_init();
	if (!data.link)
		return (-1);
	data.window = mlx_new_window(data.link, 1920, 1080, "FDF");
	if (!data.window)
	{
		mlx_destroy_display(data.link);
		return (-1);
	}
	draw_line(&data, &pt0, &pt1);
	mlx_key_hook(data.window, &close_window, &data);
	mlx_loop(data.link);
	return (0);
}
