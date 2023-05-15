/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:42:12 by llaurenc          #+#    #+#             */
/*   Updated: 2023/04/11 15:51:05 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
void	ft_gnl_bzero(void *s, size_t n);
void	*ft_gnl_calloc(size_t count, size_t size);
char	*ft_gnl_strchr(char *s, int c);
int		ft_gnl_strlen(char	*s);

#endif
