#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;
	int		ret_count;

	ret_count = 0;
	if (argc == 2)
	{
		i = 1;
		fd = open(argv[1], O_RDONLY);
		ft_putstr("===Begin===");
		while (1 == get_next_line(fd, &line))
			{
				ft_putstr("\nLine ");
				ft_putnbr(i++);
				ft_putchar('\n');
				ft_putstr(line);
				ret_count++;
			}
		ft_putnbr(ret_count);
		close(fd);
		ft_putstr("\n===Complete===");
	}
	return (0);
}
