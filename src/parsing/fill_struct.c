/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:57:47 by nseon             #+#    #+#             */
/*   Updated: 2025/02/19 18:07:11 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "stdlib.h"
#include "fdf.h"

int	fill_link(t_data *data)
{
	data->link = mlx_init();
	if (!data->link)
		return (1);
	data->window = mlx_new_window(data->link, WIDTH, HEIGHT, "FDF");
	if (!data->window)
	{
		mlx_destroy_display(data->link);
		return (close_window(data));
	}
	data->z = 1;
	return (0);
}
