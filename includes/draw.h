/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:01:52 by nseon             #+#    #+#             */
/*   Updated: 2025/02/17 17:56:18 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "struct.h"

void	draw_line(t_point pt0, t_point pt1, t_img img);
void	print_map(t_data *data);
void	put_pixel(t_img img, t_point pt);

#endif
