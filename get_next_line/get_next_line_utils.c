/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:17:52 by llaurenc          #+#    #+#             */
/*   Updated: 2023/04/17 12:07:34 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_gnl_bzero(void	*s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= 9223372000000000000 || size >= 9223372000000000000)
		return (0);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_gnl_bzero(ptr, count * size);
	return (ptr);
}

int	ft_gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_gnl_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	str = malloc (sizeof(char) * ((ft_gnl_strlen(s1) + ft_gnl_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_gnl_strchr(char *str, int c)
{
	size_t	i;

	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}
