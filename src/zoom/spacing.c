/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:58 by nseon             #+#    #+#             */
/*   Updated: 2025/03/05 13:22:14 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_printf.h"

void	spacing(t_data *data)
{
	if (data->size_line > data->nb_line)
		data->zoom = WIDTH / (data->size_line << 1);
	else
		data->zoom = HEIGHT / (data->size_line << 1);
	data->shift_x = (WIDTH - (data->size_line - 1) * (data->zoom + 1)) / 2;
	data->shift_y = (HEIGHT - (data->nb_line - 1) * (data->zoom + 1)) / 2;
}
