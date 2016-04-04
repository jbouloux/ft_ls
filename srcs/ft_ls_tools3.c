#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

int	get_major(dev_t st_rdev)
{
	int major;

	major = st_rdev;
	while ((major / 256) > 0)
        major = major / 256;
	return (major);
}

int	get_minor(dev_t st_rdev)
{
	int minor;

	minor = st_rdev % 256;
	return (minor);
}

char	*create_error(char *error, char *path)
{
	char	*str;
	char 	*name;

	name = get_last_word(path);
	str = ft_strjoin("ft_ls: ", name);
	str = ft_strrejoin(str, str, ": ");
	str = ft_strrejoin(str, str, error);
	str = ft_strrejoin(str, str, "\n\n");
	free(name);
	return (str);
}

int		check_dir(char *path)
{
	DIR *current;

	if (!(current = opendir(path)))
	{
		ft_putstr("ft_ls: ");
		perror(path);
		return (0);
	}
	else
	{
		closedir(current);
		return (1);
	}
}