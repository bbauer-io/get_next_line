#include "get_next_line.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;

	if (argc == 4)
	{
		i = 1;
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		ft_putstr("===Begin===");
		while (i < 6)
			{
				ft_putstr("\n-->Line--> ");
				ft_putnbr(i);
				get_next_line(fd, &line);
				ft_putstr("\nfd: ");
				ft_putnbr(fd);
				ft_putchar('\n');
				ft_putstr(line);
				get_next_line(fd2, &line);
				ft_putstr("\nfd: ");
				ft_putnbr(fd2);
				ft_putchar('\n');
				ft_putstr(line);
				get_next_line(fd3, &line);
				ft_putstr("\nfd: ");
				ft_putnbr(fd3);
				ft_putchar('\n');
				ft_putstr(line);
				i++;
			}
		close(fd);
		close(fd2);
		close(fd3);
		ft_putstr("\n===Complete===");
	}
	return (0);
}
