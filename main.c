#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;

	ft_putstr("hello?");
	if (argc == 2)
	{
		i = 0;
		ft_putstr("FORTHELOVEOFGOD,OPEN");
		fd = open(argv[1], O_RDONLY);
		ft_putstr("===Begin===");
		while (1 == get_next_line(fd, &line))
			{
				ft_putstr("\nLine ");
				ft_putnbr(i++);
				ft_putchar('\n');
				ft_putstr(line);
			}
		close(fd);
		ft_putstr("===Complete===");
	}
	return (0);
}
