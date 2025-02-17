/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:21:35 by nseon             #+#    #+#             */
/*   Updated: 2025/02/17 18:59:10 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "libft.h"
#include "mlx.h"
#include "ft_printf.h"

void	put_pixel(t_img img, t_point pt)
{
	char	*tab;

	tab = img.pxls + pt.y * img.len + pt.x * img.bits / 8;
	*(int *)tab = pt.color;
}
