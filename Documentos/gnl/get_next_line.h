/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrodri <natrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:16:33 by natrodri          #+#    #+#             */
/*   Updated: 2024/10/23 17:33:42 by natrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

size_t	ft_strlen(const char	*s);
size_t	ft_strlcpy(char	*dest, const char	*src, size_t	size);

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char	*s, int	c);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char	*s1, char const	*s2);

#endif
