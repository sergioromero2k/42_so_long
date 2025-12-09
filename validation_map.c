/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:24:14 by serromer          #+#    #+#             */
/*   Updated: 2025/12/09 16:48:22 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "so_long.h"





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
