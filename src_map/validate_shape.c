/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:21:41 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/09 16:48:32 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

void	validate_shape(char **map)
{
	int		i;
	size_t	expected_length;

	i = 0;
	if (!map || !map[0])
		ft_error("Error: The map is empty. ");
	expected_length = ft_strlen(map[0]);
	if (expected_length == 0)
		ft_error("Error: The first line of the map is empty. ");
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != expected_length)
			ft_error("Error: The map isn't rectangular (the rows are not the same length). ");
		i++;
	}
}
