/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:16:50 by nseon             #+#    #+#             */
/*   Updated: 2024/11/29 11:26:21 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_list	args_bis;
	int		len;
	char	*tab;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	len = str_size(format, args);
	tab = malloc(len * sizeof(char) + 1);
	if (tab == NULL)
		return (0);
	va_start(args_bis, format);
	fill(tab, format, args_bis);
	len = write(1, tab, len);
	free(tab);
	return (len);
}
