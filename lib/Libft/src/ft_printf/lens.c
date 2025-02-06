/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:42 by nseon             #+#    #+#             */
/*   Updated: 2024/11/29 11:26:28 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
We count the total size of the string we're going to malloc
*/

static int	p_size(unsigned long long int nb)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (3);
	while (nb >= 16)
	{
		n++;
		nb /= 16;
	}
	return (n + 1);
}

static int	nb_size(long long int nb, int div)
{
	int	n;

	n = 0;
	if (nb < 0)
	{
		n++;
		nb *= -1;
	}
	while (nb >= div)
	{
		n++;
		nb /= div;
	}
	return (n + 1);
}

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

static int	size_format(const char *format, va_list args, int i)
{
	if (format[i + 1] == 'c' || format[i + 1] == '%')
	{
		if (format[i + 1] == 'c')
			va_arg(args, int);
		return (1);
	}
	else if (format[i + 1] == 's')
		return (ft_strlen2(va_arg(args, char *)));
	else if (format[i + 1] == 'p')
		return (2 + p_size((unsigned long long int)(va_arg(args, void *))));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (nb_size(va_arg(args, int), 10));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		return (nb_size(va_arg(args, unsigned int), 16));
	else if (format[i + 1] == 'u')
		return (nb_size(va_arg(args, unsigned int), 10));
	else
		return (0);
}

int	str_size(const char *format, va_list args)
{
	int	i;
	int	len;
	int	minus;

	minus = 0;
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && check(format, i))
		{
			len += size_format(format, args, i);
			minus += 2;
			i += 2;
		}
		else
			i++;
	}
	return (len + i - minus);
}
