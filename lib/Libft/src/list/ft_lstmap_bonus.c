/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:02:10 by nseon             #+#    #+#             */
/*   Updated: 2024/11/20 15:55:04 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*temp;

	map = NULL;
	while (lst)
	{
		temp = ft_lstnew(0);
		if (!temp)
		{
			ft_lstclear(&map, del);
			return (0);
		}
		temp->content = f(lst->content);
		ft_lstadd_back(&map, temp);
		lst = lst->next;
	}
	return (map);
}
