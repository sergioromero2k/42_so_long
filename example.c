/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio-alejandro <sergio-alejandro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:17:04 by sergio-alej       #+#    #+#             */
/*   Updated: 2025/12/06 07:32:05 by sergio-alej      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
}
void	read_map_chars(char **map)
{
	char	c;

	for (int i = 0; map[i] != NULL; i++)
	{
		for (int j = 0; map[i][j] != '\0'; j++)
		{
			c = map[i][j];
			printf("map[%d][%d] = %c\n", i, j, c);
		}
	}
}

int	main(void)
{
	char	*map[] = {"#######", "#  P  #", "#     #", "#######", NULL};

	print_map(map);
    printf("\n");
    read_map_chars(map);
}
