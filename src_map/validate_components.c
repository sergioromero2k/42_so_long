/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:47:55 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/09 17:11:10 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

static void	check_counts(int p_count, int e_count, int c_count)
{
	if (p_count != 1)
		ft_error("Error: You Must have exactly one player ('P'). ");
	if (e_count != 1)
		ft_error("Error: Must have exactly one output ('E'). ");
	if (c_count < 1)
		ft_error("Error: Must have at least one collectible item ('C'). ");
}
static void	count_components(char *line, int counts[3])
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'P')
			counts[0]++;
		else if (line[j] == 'E')
			counts[1]++;
		else if (line[j] == 'C')
			counts[2]++;
		else if (line[j] != '0' && line[j] != '1')
			ft_error("Error: Map contains invalid characters.");
		j++;
	}
}

void	validate_components(char **map)
{
	int i;
	int counts[3];

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = 0;
	while (map[i])
	{
		count_components(map[i], counts);
		i++;
	}
	check_counts(counts[0], counts[1], counts[2]);
}
