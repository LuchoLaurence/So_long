/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:18:19 by llaurenc          #+#    #+#             */
/*   Updated: 2023/04/26 14:27:21 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_map
{
	int		count_c;
	int		count_e;
	int		count_p;
	void	*sol;
	void	*mur;
	void	*player;
	void	*collec;
	void	*exit;
}	t_map;

typedef struct s_all
{
	char	**map;
	int		ysize;
	size_t	xsize;
	t_map	carte;
	int		yplayer;
	size_t	xplayer;
	void	*img;
	void	*mlx;
	void	*win;
	int		move;
}	t_all;

int		verif_args(int argc, char **argv);
int		verif_map(char *argv, t_all *data);
void	ft_error(char *str);
void	stock_map(char *argv, t_all *data);
int		ft_nbr_ligne(int file);
int		ft_verif_x(t_all *data);
int		ft_check_border(t_all *data);
void	ft_verif_elem(t_all *data);
void	ft_check_elem(t_all *data);
void	ft_find_player(t_all *data);
void	ft_copy(t_all *data);
void	ft_propagation(t_all *data, char **copy);
void	ft_virus(char **copy, size_t x, int y);
void	ft_virus2(char **copy, size_t x, int y);
void	ft_show_map(t_all *data);
void	ft_sprite(t_all *data);
int		ft_move(int keycode, t_all *data);
void	ft_up(t_all *data);
void	ft_down(t_all *data);
void	ft_right(t_all *data);
void	ft_left(t_all *data);
void	ft_close_wind(t_all *data);

#endif