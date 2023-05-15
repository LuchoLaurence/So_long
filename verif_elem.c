/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:56:32 by llaurenc          #+#    #+#             */
/*   Updated: 2023/04/24 10:20:21 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif_elem(t_all *data)
{
	size_t	x;
	int		y;

	y = 0;
	while (y < data->ysize - 2)
	{
		x = 0;
		while (x < data->xsize - 1)
		{
			if (data->map[y][x] != 'C' && data->map[y][x] != 'P'
			&& data->map[y][x] != 'E' && data->map[y][x] != '0'
			&& data->map[y][x] != '1')
				ft_error("La map ne peut contenir que P, E, C, 0 ou 1");
			x++;
		}
		y++;
	}
	return ;
}

void	ft_count_elem(t_all *data)
{
	if (data->carte.count_c < 1)
		ft_error("Nombre de collectifs invalides");
	if (data->carte.count_e != 1)
		ft_error("Erreur dans le nombre d'exit");
	if (data->carte.count_p != 1)
		ft_error("Erreur dans le nombre de joueur");
}

void	ft_check_elem(t_all *data)
{
	size_t	x;
	int		y;

	data->carte.count_c = 0;
	data->carte.count_e = 0;
	data->carte.count_p = 0;
	y = 0;
	while (y < data->ysize - 1)
	{
		x = 0;
		while (x < data->xsize - 1)
		{
			if (data->map[y][x] == 'C')
				data->carte.count_c++;
			if (data->map[y][x] == 'E')
				data->carte.count_e++;
			if (data->map[y][x] == 'P')
				data->carte.count_p++;
			x++;
		}
		y++;
	}
	ft_count_elem(data);
	return ;
}
