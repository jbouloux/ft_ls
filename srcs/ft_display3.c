#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void	display_link(char *path)
{
	char *buf;

	buf = ft_strnew(256);
	if ((readlink(path, buf, 256)) == -1)
	{
		perror("readlink");
		ft_putchar('\n');
		return;
	}
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(buf);
}

void	display_major_minor(dev_t st_rdev, int *padtab)
{
	int major;
	int minor;

	major = get_major(st_rdev);
	minor = get_minor(st_rdev);
    ft_putchar(' ');
    display_padding(major, padtab[4]);
    ft_putstr(", ");
    display_padding(minor, padtab[5]);
    ft_putchar(' ');
}