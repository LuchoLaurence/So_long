/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:18:52 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/09 09:19:52 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_wind(t_all *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_all	data;

	if (verif_args(argc, argv) != 0)
		ft_error("Arguments incorrects");
	if (verif_map (argv[1], &data))
		ft_error("Map incorrecte");
	ft_verif_elem(&data);
	ft_check_elem(&data);
	ft_find_player(&data);
	ft_copy(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
			((data.xsize - 1) * 60), (data.ysize) * 60, "so_long");
	ft_show_map(&data);
	ft_putstr_fd("Moves : 0\n", 1);
	mlx_key_hook(data.win, ft_move, &data);
	mlx_hook(data.win, 17, 0, (int (*)())ft_close_wind, &data);
	mlx_loop(data.mlx);
	return (0);
}
