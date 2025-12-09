/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serromer <serromer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:24:14 by serromer          #+#    #+#             */
/*   Updated: 2025/12/06 18:23:56 by serromer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"

void	validate_shape(char **map)
{
	int	i;
	int	size_map;

	i = 0;
	size_map = 0;
	if (map[i])
		ft_error("Error en mapa");
	while (map[i])
	{
		size_map = ft_strlen(map[i]);
		if (size_map > ft_strlen(map[i + 1]))
			return (ft_error("Error en validacion de forma del mapa"));
		i++;
	}
}

void	validate_walls(char **map)
{
	int	i;
	int	contador;

	i = 0;
	contador = 0;
	if (!map[0])
		return (ft_error("Error primera fila mapa"));
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (ft_error("Primera columna debe ser pura 1"));
		i++;
	}
	while (map[contador] != NULL)
		contador++;
	i = 0;
	while (map[contador][i])
	{
		if (map[contador][i] != '1')
			return (ft_error("Ultima columna debe ser puro 1"));
		i++;
	}
}

void	validate_components(char **map)
{
	int	i;
	int	j;
	int	z;
	int	c;

	i = 0;
	j = 0;
	z = 0;
	c = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' || map[i][j] != '1' || map[i][j] != 'C'
				|| map[i][j] != 'E' || map[i][j] != 'P')
				return (ft_error("Solo debe contener caracteres válidos ('0', \
						'1', 'C', 'E', 'P')"));
			if (map[i][j] == 'P' || map[i][j] == 'E')
				z++;
			if (map[i][j] == 'C')
				c++;
		}
		i++;
	}
	if (z <= 1 || z > 2)
		return (ft_error("'P' y 'E' debe estar en el mapa solamente 1 vez"));
	if (c < 1)
		return (ft_error("'C' debe ser al menos 1"));
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
