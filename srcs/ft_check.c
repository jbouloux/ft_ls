/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:48:57 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:48:59 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

int	isdir(char *path)
{
	t_stat	*buf;

	buf = (t_stat *)malloc(sizeof(t_stat));
	if ((lstat(path, buf)) == -1)
	{
		free(buf);
		return (-1);
	}
	if ((buf->st_mode & S_IFMT) == S_IFDIR)
	{
		free(buf);
		return (1);
	}
	else
	{
		free(buf);
		return (0);
	}
}

int	isnavdir(char *dir)
{
	if (dir[0] == '.' && !dir[1])
		return (1);
	else if (dir[0] == '.' && dir[1] == '.' && !dir[2])
		return (1);
	else
		return (0);
}

int	check_dir(char *path)
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
