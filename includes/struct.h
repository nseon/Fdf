/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:55:48 by nseon             #+#    #+#             */
/*   Updated: 2025/02/13 16:27:41 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define WIDTH 1000
# define HEIGHT 700

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_data
{
	void	*link;
	void	*window;
	void	*image;
	int		size_line;
	int		nb_line;
	t_point	*pts;
}	t_data;

typedef struct s_img
{
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

#endif
