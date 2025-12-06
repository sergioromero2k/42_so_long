#include "ft_printf.h"
#include "so_long.h"
#include "get_next_line.h"

void	read_map(char *filepath)
{
    char **map;
    int fd;
    
    fd=open(filepath, O_RDONLY);
    if(fd<0)
        return ;
    
    
    
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
