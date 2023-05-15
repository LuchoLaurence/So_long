/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:07:47 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/03 08:45:36 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprite(t_all *data)
{
	int	x;
	int	y;

	data->carte.mur = mlx_xpm_file_to_image
		(data->mlx, "./image/mur.xpm", &x, &y);
	data->carte.sol = mlx_xpm_file_to_image
		(data->mlx, "./image/sol.xpm", &x, &y);
	data->carte.player = mlx_xpm_file_to_image
		(data->mlx, "./image/luigi.xpm", &x, &y);
	data->carte.exit = mlx_xpm_file_to_image
		(data->mlx, "./image/door.xpm", &x, &y);
	data->carte.collec = mlx_xpm_file_to_image
		(data->mlx, "./image/boo.xpm", &x, &y);
}

void	ft_draw_map(t_all *data, size_t x, int y)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx,
			data->win, data->carte.mur, x * 60, y * 60);
	if (data->map[y][x] == '0' || data->map[y][x] == 'C'
		|| data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx,
			data->win, data->carte.sol, x * 60, y * 60);
	if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx,
			data->win, data->carte.collec, x * 60, y * 60);
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx,
			data->win, data->carte.player, x * 60, y * 60);
	if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx,
			data->win, data->carte.exit, x * 60, y * 60);
}

void	ft_show_map(t_all *data)
{
	int		y;
	size_t	x;

	ft_sprite(data);
	y = 0;
	while (y < data->ysize)
	{
		x = 0;
		while (x < data->xsize)
		{
			ft_draw_map(data, x, y);
			x++;
		}
		y++;
	}
}
