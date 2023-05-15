/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:48:26 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/03 09:01:26 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_all *data)
{
	if (data->map[data->yplayer - 1][data->xplayer] == '1')
		return ;
	if (data->map[data->yplayer - 1][data->xplayer] == 'E'
			&& data->carte.count_c != 0)
		return ;
	data->move++;
	if (data->map[data->yplayer - 1][data->xplayer] == 'E'
			&& data->carte.count_c == 0)
	{
		ft_putnbr_fd(data->move, 1);
		exit (0);
	}
	if (data->map[data->yplayer - 1][data->xplayer] == 'C')
	{
		data->map[data->yplayer - 1][data->xplayer] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->carte.count_c--;
	}
	if (data->map[data->yplayer - 1][data->xplayer] == '0')
	{
		data->map[data->yplayer - 1][data->xplayer] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
	}
	ft_putnbr_fd(data->move, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_down(t_all *data)
{
	if (data->map[data->yplayer + 1][data->xplayer] == '1')
		return ;
	if (data->map[data->yplayer + 1][data->xplayer] == 'E'
			&& data->carte.count_c != 0)
		return ;
	data->move++;
	if (data->map[data->yplayer + 1][data->xplayer] == 'E'
			&& data->carte.count_c == 0)
	{
		ft_putnbr_fd(data->move, 1);
		exit (0);
	}
	if (data->map[data->yplayer + 1][data->xplayer] == 'C')
	{
		data->map[data->yplayer + 1][data->xplayer] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->carte.count_c--;
	}
	if (data->map[data->yplayer + 1][data->xplayer] == '0')
	{
		data->map[data->yplayer + 1][data->xplayer] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
	}
	ft_putnbr_fd(data->move, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_right(t_all *data)
{
	if (data->map[data->yplayer][data->xplayer + 1] == '1')
		return ;
	if (data->map[data->yplayer][data->xplayer + 1] == 'E'
			&& data->carte.count_c != 0)
		return ;
	data->move++;
	if (data->map[data->yplayer][data->xplayer + 1] == 'E'
			&& data->carte.count_c == 0)
	{
		ft_putnbr_fd(data->move, 1);
		exit (0);
	}
	if (data->map[data->yplayer][data->xplayer + 1] == 'C')
	{
		data->map[data->yplayer][data->xplayer + 1] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->carte.count_c--;
	}
	if (data->map[data->yplayer][data->xplayer + 1] == '0')
	{
		data->map[data->yplayer][data->xplayer + 1] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
	}
	ft_putnbr_fd(data->move, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_left(t_all *data)
{
	if (data->map[data->yplayer][data->xplayer - 1] == '1')
		return ;
	if (data->map[data->yplayer][data->xplayer - 1] == 'E'
			&& data->carte.count_c != 0)
		return ;
	data->move++;
	if (data->map[data->yplayer][data->xplayer - 1] == 'E'
			&& data->carte.count_c == 0)
	{
		ft_putnbr_fd(data->move, 1);
		exit (0);
	}
	if (data->map[data->yplayer][data->xplayer - 1] == 'C')
	{
		data->map[data->yplayer][data->xplayer - 1] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
		data->carte.count_c--;
	}
	if (data->map[data->yplayer][data->xplayer - 1] == '0')
	{
		data->map[data->yplayer][data->xplayer - 1] = 'P';
		data->map[data->yplayer][data->xplayer] = '0';
	}
	ft_putnbr_fd(data->move, 1);
	ft_putstr_fd("\n", 1);
}

int	ft_move(int keycode, t_all *data)
{
	if (keycode == 53)
		exit (0);
	if (keycode == 13 || keycode == 126)
	{	
		ft_find_player(data);
		ft_up(data);
	}
	if (keycode == 125 || keycode == 1)
	{	
		ft_find_player(data);
		ft_down(data);
	}
	if (keycode == 2 || keycode == 124)
	{	
		ft_find_player(data);
		ft_right(data);
	}
	if (keycode == 0 || keycode == 123)
	{	
		ft_find_player(data);
		ft_left(data);
	}
	ft_show_map(data);
	return (0);
}
