/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:15:49 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/03 08:45:22 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_all *data)
{
	data->yplayer = 1;
	while (data->yplayer < data->ysize -1)
	{
		data->xplayer = 1;
		while (data->xplayer < data->xsize - 1)
		{
			if (data->map[data->yplayer][data->xplayer] == 'P')
				return ;
			data->xplayer++;
		}
		data->yplayer++;
	}
}

void	ft_virus2(char **copy, size_t x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == 'C' || copy[y][x] == 'T')
		return ;
	else
	{
			copy[y][x] = 'T';
		ft_virus2(copy, x + 1, y);
		ft_virus2(copy, x, y + 1);
		ft_virus2(copy, x - 1, y);
		ft_virus2(copy, x, y - 1);
	}
}

void	ft_virus(char **copy, size_t x, int y)
{
	if (copy[y][x] == '1' || copy[y][x] == 'E' || copy[y][x] == 'X')
		return ;
	else
	{
			copy[y][x] = 'X';
		ft_virus(copy, x + 1, y);
		ft_virus(copy, x, y + 1);
		ft_virus(copy, x - 1, y);
		ft_virus(copy, x, y - 1);
	}
}

void	ft_propagation(t_all *data, char **copy)
{
	int		y;
	size_t	x;

	y = 0;
	ft_virus(copy, data->xplayer, data->yplayer);
	ft_virus2(copy, data->xplayer, data->yplayer);
	while (y < data->ysize - 1)
	{
		x = 0;
		while (x < data->xsize)
		{
			if (copy[y][x] == 'C')
				ft_error("Tous les collectibles ne peuvent pas etre recuperés");
			if (copy[y][x] == 'E')
				ft_error("Le joueur ne peut pas acceder à la sortie");
			x++;
		}
		y++;
	}
}

void	ft_copy(t_all *data)
{
	char	**copy;
	int		y;

	y = 0;
	copy = malloc(sizeof(char *) * (data->ysize + 1));
	while (y < data->ysize)
	{
		copy[y] = ft_strdup(data->map[y]);
		y++;
	}
	copy[y] = NULL;
	ft_propagation(data, copy);
	y = 0;
	while (y < data->ysize)
		free(copy[y++]);
	free(copy);
	return ;
}
