#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void	ft_file_type(mode_t st_mode)
{
	ft_putstr(((st_mode & S_IFMT) == S_IFREG) ? "-" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFDIR) ? "d" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFSOCK) ? "s" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFLNK) ? "l" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFIFO) ? "p" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFBLK) ? "b" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFCHR) ? "c" : "");
}

void	ft_print_rights(mode_t st_mode)
{
	ft_file_type(st_mode);
	ft_putstr((st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((st_mode & S_IXOTH) ? "x" : "-");
}

int		get_padding_loop(t_files *tmp, int option)
{
	if (option == 1)
		return (ft_longlen((long)tmp->info->st_size));
	else if (option == 0)
		return (ft_longlen((long)tmp->info->st_nlink));
	else if (option == 2)
		return (ft_strlen((getpwuid(tmp->info->st_uid))->pw_name));
	else if (option == 3)
		return (ft_strlen((getgrgid(tmp->info->st_gid))->gr_name));
	else if (option == 4 && (S_ISCHR(tmp->info->st_mode) || \
		S_ISBLK(tmp->info->st_mode)))
		return (ft_longlen(get_major(tmp->info->st_rdev)));
	else if (option == 5 && (S_ISCHR(tmp->info->st_mode) || \
		S_ISBLK(tmp->info->st_mode)))
		return (ft_longlen(get_minor(tmp->info->st_rdev)));
	else
		return (0);
}

int		get_padding(t_files *begin, int option)
{
	int		result;
	int		buf;
	t_files *tmp;

	tmp = begin;
	result = 0;
	buf = 0;
	while (tmp)
	{
		buf = get_padding_loop(tmp, option);
		if (buf > result)
			result = buf;
		tmp = tmp->next;
	}
	return (result);
}
