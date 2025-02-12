/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:55:48 by nseon             #+#    #+#             */
/*   Updated: 2025/02/12 13:27:06 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int		size_line;
	int		nb_line;
	t_point	*pts;
}	t_data;

#endif
