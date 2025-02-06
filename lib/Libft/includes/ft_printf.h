/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:42:28 by nseon             #+#    #+#             */
/*   Updated: 2024/11/28 17:10:49 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		str_size(const char *format, va_list args);
char	*uitoa_base(unsigned long long int n, char c,
			char *base, unsigned int div);
void	fill(char *tab, const char *format, va_list args);
int		ft_strlen2(const char *s);

#endif
