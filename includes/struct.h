/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:55:48 by nseon             #+#    #+#             */
/*   Updated: 2025/02/17 14:00:16 by nseon            ###   ########.fr       */
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
	int	color;
}	t_point;

typedef struct s_data
{
	void	*link;
	void	*window;
	void	*img;
	int		size_line;
	int		nb_line;
	t_point	*pts;
}	t_data;

typedef struct s_img
{
	char	*pxls;
	int		bits;
	int		len;
	int		endian;
}	t_img;

#endif
