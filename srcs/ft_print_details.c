/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_details.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:50:38 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:50:40 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

static	void	ft_file_type(mode_t st_mode)
{
	ft_putstr(((st_mode & S_IFMT) == S_IFREG) ? "-" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFDIR) ? "d" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFSOCK) ? "s" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFLNK) ? "l" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFIFO) ? "p" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFBLK) ? "b" : "");
	ft_putstr(((st_mode & S_IFMT) == S_IFCHR) ? "c" : "");
}

void			ft_print_rights(mode_t st_mode)
{
	ft_file_type(st_mode);
	ft_putstr((st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((st_mode & S_IWUSR) ? "w" : "-");
	if (st_mode & S_IXUSR)
		ft_putstr((st_mode & S_ISUID) ? "s" : "x");
	else
		ft_putstr((st_mode & S_ISUID) ? "S" : "-");
	ft_putstr((st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((st_mode & S_IWGRP) ? "w" : "-");
	if (st_mode & S_IXGRP)
		ft_putstr((st_mode & S_ISGID) ? "s" : "x");
	else
		ft_putstr((st_mode & S_ISGID) ? "S" : "-");
	ft_putstr((st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((st_mode & S_IWOTH) ? "w" : "-");
	if (st_mode & S_IXOTH)
		ft_putstr((st_mode & S_ISVTX) ? "t" : "x");
	else
		ft_putstr((st_mode & S_ISVTX) ? "T" : "-");
}

void			display_date(time_t date)
{
	char	*str1;
	char	*str2;
	time_t	actualtime;

	actualtime = time(0);
	str1 = ctime(&date);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void			display_link(char *path)
{
	char *buf;

	buf = ft_strnew(256);
	if ((readlink(path, buf, 256)) == -1)
	{
		perror("readlink");
		ft_putchar('\n');
		return ;
	}
	ft_putstr(" -> ");
	ft_putstr(buf);
	free(buf);
}

void			display_major_minor(dev_t st_rdev, int *padtab)
{
	int major;
	int minor;

	major = get_major(st_rdev);
	minor = get_minor(st_rdev);
	ft_putchar(' ');
	display_padding(major, padtab[4]);
	ft_putstr(", ");
	display_padding(minor, padtab[5]);
}
