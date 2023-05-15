/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:10:10 by llaurenc          #+#    #+#             */
/*   Updated: 2023/04/21 09:14:46 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_args(int argc, char **argv)
{
	int		i;
	char	*ber;

	i = 0;
	if (argc != 2)
		return (1);
	i = ft_strlen(argv[1]);
	ber = ft_substr(argv[1], i - 4, 4);
	if (ft_strcmp(ber, ".ber") != 0)
	{
		free(ber);
		return (1);
	}
	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		close(i);
		free(ber);
		ft_error("Fichier incorrect");
	}
	free(ber);
	return (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(1);
}
