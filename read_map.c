/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:22:41 by serromer          #+#    #+#             */
/*   Updated: 2025/12/06 18:03:35 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	read_map(char *filepath, t_game *game)
{
	char	**map;
	int		fd;
	int		*line;
	int		rows;

	map = NULL;
	rows = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		ft_error("No se pudo abrir el archivo del mapa");
	while ((line = get_next_line(fd)))
	{
		map = append_line(map, line);
		free(line);
		rows++;
	}
	close(fd);
	if (rows == 0)
		ft_error("Mapa vacio");
	game->map = map;
	game->height = rows;
	if (game->map[0])
		game->width = ft_strlen(game->map[0]) - 1;
	if ((game->height) > (game->width))
		return (ft_error("El mapa debe ser cuadrado"));
}

int	append_line(char **arr, const char *line)
{
	int	**new_map;
	int	i;
	int	current_size;

	current_size = 0;
	if (arr)
	{
		while (arr[current_size])
			current_size++;
	}
	new_map = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	if (!new_map)
		ft_error("Error en asignación memoria");
	while (i < current_size)
	{
		new_map[i] = arr[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	if (arr)
		free(arr);
	return (NULL);
}
