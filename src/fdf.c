/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:53:13 by nseon             #+#    #+#             */
/*   Updated: 2025/02/17 18:06:57 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "struct.h"
#include "draw.h"
#include <fcntl.h>
#include "parsing.h"
#include "ft_printf.h"
#include "zoom.h"

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
			return (close_window(0, &data));
		mlx_key_hook(data.window, &close_window, &data);
		spacing(&data);
		print_map(&data);
		mlx_loop(data.link);
		free_all(&data);
	}
	return (0);
}
