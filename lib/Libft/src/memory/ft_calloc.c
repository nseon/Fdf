/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:38:43 by nseon             #+#    #+#             */
/*   Updated: 2025/02/05 13:32:01 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;

	if (size != 0 && nmemb > INT_MAX / size)
		return (0);
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (0);
	ft_bzero(tab, nmemb * size);
	return ((void *)tab);
}
