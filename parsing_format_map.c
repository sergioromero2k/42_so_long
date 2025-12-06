#include "ft_printf.h"
#include "so_long.h"

void	ft_error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
int	check_bet_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (EXIT_FAILURE);
	if (ft_strncmp(filename + len - 4, ".ber" == 0))
		return (1);
	return (EXIT_FAILURE);
}
