/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:08 by nseon             #+#    #+#             */
/*   Updated: 2025/02/20 14:33:01 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		map(int fd, t_data *data);
int		fill_link(t_data *data);
void	fill_data(t_data *data, int y, char **z);

#endif
