#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;
	int		fd2;

	if (argc == 3)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		ft_putstr("===Begin===");
		while (i < 6)
			{
				get_next_line(fd, &line);
				ft_putstr("\nfd: ");
				ft_putnbr(fd);
				ft_putstr("\nLine ");
				ft_putnbr(i);
				ft_putchar('\n');
				ft_putstr(line);
				get_next_line(fd2, &line);
				ft_putstr("\nfd: ");
				ft_putnbr(fd2);
				ft_putstr("\nLine ");
				ft_putnbr(i++);
				ft_putchar('\n');
				ft_putstr(line);
			}
		close(fd);
		close(fd2);
		ft_putstr("\n===Complete===");
	}
	return (0);
}
