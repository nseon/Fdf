/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:42 by nseon             #+#    #+#             */
/*   Updated: 2025/01/14 12:15:32 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

/*
fill the malloc
*/

static int	check(const char *format, int i)
{
	i++;
	if (format[i] == 'c' || format[i] == '%' || format[i] == 's'
		|| format[i] == 'p' || format[i] == 'd' || format[i] == 'i'
		|| format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
		return (1);
	else
		return (0);
}

static int	str_fill(char *dst, char *src, int j, char c)
{
	int	i;
	int	check;

	check = 1;
	i = 0;
	if (c == 'p' && ft_strncmp(src, "(nil)", 5))
	{
		dst[j++] = '0';
		dst[j++] = 'x';
	}
	if (c == 's')
		check = 0;
	if (src == NULL )
		src = "(null)";
	while (src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (check == 1 && ft_strncmp(src, "(nil)", 5))
		free(src);
	return (j);
}

int	fill_char(char *tab, char c, int j)
{
	tab[j] = c;
	return (j + 1);
}

static int	fill_format(char c, va_list args, int j, char *tab)
{
	if (c == 'c')
		return (fill_char(tab, (char)(va_arg(args, int)), j));
	else if (c == '%')
		return (fill_char(tab, '%', j));
	else if (c == 's')
		return (str_fill(tab, va_arg(args, char *), j, c));
	else if (c == 'd' || c == 'i')
		return (str_fill(tab, ft_itoa(va_arg(args, int)), j, c));
	else if (c == 'x' || c == 'X')
		return (str_fill(tab, uitoa_base(va_arg(args, unsigned int)
					, c, "0123456789abcdef", 16), j, c));
	else if (c == 'p')
		return (str_fill(tab, uitoa_base((unsigned long long int)
					va_arg(args, void *), c, "0123456789abcdef", 16), j, c));
	else if (c == 'u')
		return (str_fill(tab, uitoa_base(va_arg(args, unsigned int)
					, c, "0123456789", 10), j, c));
	return (0);
}

void	fill(char *tab, const char *format, va_list args)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && check(format, i))
		{
			j = fill_format(format[i + 1], args, j, tab);
			i += 2;
		}
		else
		{
			tab[j] = format[i];
			i++;
			j++;
		}
	}
}
