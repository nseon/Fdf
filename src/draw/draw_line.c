/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:54:01 by nseon             #+#    #+#             */
/*   Updated: 2025/02/17 17:56:13 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "draw.h"

int	abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	draw_horizontal_line(t_point pt0, t_point pt1, t_img img)
{
	int	dx;
	int	dy;
	int	dir;
	int	p;

	dx = pt1.x - pt0.x;
	dy = pt1.y - pt0.y;
	dir = -1 * (dy < 0) + 1 * (dy > 0);
	dy *= dir;
	p = 2 * dy - dx;
	while (pt0.x <= pt1.x)
	{
		put_pixel(img, pt0);
		if (p >= 0)
		{
			pt0.y += dir;
			p -= 2 * dx;
		}
		p += 2 * dy;
		pt0.x++;
	}
}

void	draw_vertical_line(t_point pt0, t_point pt1, t_img img)
{
	int	dx;
	int	dy;
	int	dir;
	int	p;

	dx = pt1.x - pt0.x;
	dy = pt1.y - pt0.y;
	dir = -1 * (dy < 0) + 1 * (dy > 0);
	dy *= dir;
	p = 2 * dx - dy;
	while (pt0.y <= pt1.y)
	{
		put_pixel(img, pt0);
		if (p >= 0)
		{
			pt0.x += dir;
			p -= 2 * dy;
		}
		p += 2 * dx;
		pt0.y++;
	}
}

void	draw_line(t_point pt0, t_point pt1, t_img img)
{
	if (abs(pt1.x - pt0.x) > abs(pt1.y - pt0.y))
	{
		if (pt0.x > pt1.x)
			draw_horizontal_line(pt1, pt0, img);
		else
			draw_horizontal_line(pt0, pt1, img);
	}
	else
	{
		if (pt0.y > pt1.y)
			draw_vertical_line(pt1, pt0, img);
		else
			draw_vertical_line(pt0, pt1, img);
	}
}
