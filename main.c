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

int	main(int argc, char *argv[])
{
	char	*ptr;

	if (argc != 2)
	{
		ft_printf("Número incorrecto de argumento, Uso: ./so_long <mapa.ber>");
		return (EXIT_FAILURE);
	}
	if (!check_bet_extension(argv[1]))
		ft_error("La extensión del mapa debe ser .ber");
	return (0);
}
