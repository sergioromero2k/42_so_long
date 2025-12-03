#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	*ptr;

	if (argc != 2)
		return (printf("Error p"), EXIT_FAILURE);
	ptr = &(*argv[1]);
	while (*ptr != '.')
		ptr++;
	ptr++;
	if (*ptr != 'b')
		return (printf("Error b"), EXIT_FAILURE);
	ptr++;
	if (*ptr != 'e')
		return (printf("Error e"), EXIT_FAILURE);
	ptr++;
	if (*ptr != 'r')
		return (printf("Error r"), EXIT_FAILURE);
}
