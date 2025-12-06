#ifndef SOLONG
# define SOLONG

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		collected;
	int		moves;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_game;

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void		ft_error(char *msg);
int			check_bet_extension(char *filename);

#endif
