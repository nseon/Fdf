/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:58 by nseon             #+#    #+#             */
/*   Updated: 2025/03/04 13:53:35 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strnjoin2(char **s1, char *s2, int n);
char	*get_next_line(int fd, int check);
char	*ft_substr2(char **s, int start);
char	*null_free(char **str, int check);

#endif
