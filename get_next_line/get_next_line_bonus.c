/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaurenc <llaurenc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:19 by llaurenc          #+#    #+#             */
/*   Updated: 2023/04/11 15:54:03 by llaurenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_new_temp(char *temp)
{
	char	*new_temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = i;
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!temp[i])
		return (free(temp), NULL);
	new_temp = malloc(sizeof(char) * ((ft_gnl_strlen(temp) - i) + 1));
	if (new_temp == NULL)
		return (free(new_temp), NULL);
	i++;
	while (temp[i])
		new_temp[j++] = temp[i++];
	free(temp);
	new_temp[j] = '\0';
	return (new_temp);
}

static char	*ft_line(char *temp)
{
	int		i;
	char	*line;

	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] != '\n' && temp[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i])
	{
		line[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read(char *temp, int fd)
{
	char	*buff;
	int		size;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (free(buff), NULL);
	size = 1;
	while (size > 0 && !(ft_gnl_strchr(temp, '\n')))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		temp = ft_gnl_strjoin(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		if (temp[fd])
			free(temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	temp[fd] = ft_read(temp[fd], fd);
	if (temp[fd] == NULL)
		return (free(temp[fd]), NULL);
	line = ft_line(temp[fd]);
	temp[fd] = ft_new_temp(temp[fd]);
	return (line);
}
