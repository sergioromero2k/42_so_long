/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:33:02 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/09 16:46:15 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

void	validate_walls(char **map)
{
	int		i;
	int		last_row;
	size_t	last_col;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			ft_error("Error: The first row isn't a complete wall. ");
		i++;
	}
	last_col = i - 1;
	last_row = 0;
	while (map[last_row + 1] != NULL)
		last_row++;
	i = 0;
	while (map[last_row][i])
	{
		if (map[last_row][i] != '1')
			ft_error("Error: The last col ins't a complete wall. ");
		i++;
	}
	validate_col(map, last_col);
}

void	validate_col(char **map, int last_col)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1')
			ft_error("Error: The first col isn't a complete wall. ");
		if (map[i][last_col] != '1')
			ft_error("Error: The last col isn't complete wall. ");
		i++;
	}
}
