/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:30:57 by llaurenc          #+#    #+#             */
/*   Updated: 2023/05/03 09:42:19 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_border(t_all *data)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < data->xsize - 1)
	{
		if (data->map[0][i] != '1')
			return (1);
		if (data->map[data->ysize - 1][i] != '1')
			return (1);
		i++;
	}
	while (j < data->ysize - 2)
	{
		if (data->map[j][0] != '1' || data->map[j][data->xsize - 2] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	ft_verif_x(t_all *data)
{
	int	i;

	i = 0;
	while (i < data->ysize - 1)
	{
		if (ft_strlen(data->map[i]) != data->xsize)
			return (1);
		i++;
	}
	if (ft_strlen(data->map[i]) != data->xsize - 1)
		return (1);
	return (0);
}

void	stock_map(char *argv, t_all *data)
{
	int		file;
	int		i;
	char	*temp;
	char	*line;

	i = 0;
	file = open(argv, O_RDONLY);
	if (file == -1)
		ft_error("Fichier incorrect");
	data->ysize = ft_nbr_ligne(file);
	close(file);
	file = open(argv, O_RDONLY);
	data->map = malloc(sizeof(char *) * (data->ysize + 1));
	while (i < data->ysize)
	{
		line = get_next_line(file);
		temp = ft_strdup(line);
		free(line);
		data->map[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	close(file);
	data->map[i] = NULL;
	data->xsize = ft_strlen(data->map[0]);
}

int	verif_map(char *argv, t_all *data)
{
	stock_map(argv, data);
	if (ft_verif_x(data))
		return (1);
	if (ft_check_border(data))
		return (1);
	return (0);
}

int	ft_nbr_ligne(int file)
{
	int		nbligne;
	char	*line;

	nbligne = 0;
	line = get_next_line(file);
	if (!line)
	{
		free(line);
		ft_error("file is empty");
	}
	nbligne++;
	while (line)
	{
		free(line);
		line = get_next_line(file);
		nbligne++;
	}
	free(line);
	return (nbligne - 1);
}
