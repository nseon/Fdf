/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:35:18 by nseon             #+#    #+#             */
/*   Updated: 2025/03/04 11:59:44 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

int	click(int keycode, int x, int y, t_data *data);
int	unclick(int keycode, int x, int y, t_data *data);
int	redirect_signals(int keycode, t_data *data);

#endif
