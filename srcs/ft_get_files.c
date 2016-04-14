/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:50:14 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:50:15 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void			printfiles(t_dir *tmp)
{
	ft_putstr(tmp->path);
	ft_putstr(":\n");
	while (tmp->files)
	{
		ft_putstr(tmp->files->name);
		ft_putchar('\n');
		tmp->files = tmp->files->next;
	}
}

t_env			*pre_get_files(t_dir *begin, t_env *env)
{
	t_dir *tmp;

	tmp = begin;
	while (tmp)
	{
		tmp->files = get_files(tmp, env->flags[2]);
		if (tmp->sousdir)
			env = pre_get_files(tmp->sousdir, env);
		tmp = tmp->next;
	}
	return (env);
}

static void		gfloop(t_dirent *file, t_files *tmp, t_dir *rep, int hidden)
{
	char *path;

	if (file->d_name[0] != '.' || hidden)
	{
		while (tmp->next)
			tmp = tmp->next;
		path = file_path(rep->path, file->d_name);
		tmp->next = add_file(path);
		tmp->next->info = (t_stat *)malloc(sizeof(t_stat));
		tmp->next->name = file->d_name;
		lstat(path, tmp->next->info);
		tmp = tmp->next;
		free(path);
	}
}

static t_dirent	*gfverif(DIR *current, t_dir *directory, int hidden)
{
	t_dirent		*cur_file;

	if (!current)
	{
		directory->error = create_error(strerror(errno), directory->path);
		return (NULL);
	}
	if (!(cur_file = readdir(current)))
	{
		closedir(current);
		return (NULL);
	}
	while (cur_file->d_name[0] == '.' && !hidden)
	{
		cur_file = readdir(current);
		if (!cur_file)
		{
			closedir(current);
			return (NULL);
		}
	}
	return (cur_file ? cur_file : NULL);
}

t_files			*get_files(t_dir *directory, int hidden)
{
	DIR			*current;
	t_dirent	*cur_file;
	t_files		*buf;
	t_files		*tmp;
	char		*path;

	current = opendir(directory->path);
	if (!(cur_file = gfverif(current, directory, hidden)))
		return (NULL);
	path = file_path(directory->path, cur_file->d_name);
	buf = add_file(path);
	buf->info = (t_stat *)malloc(sizeof(t_stat));
	buf->name = cur_file->d_name;
	lstat(path, buf->info);
	free(path);
	cur_file = readdir(current);
	tmp = buf;
	while (cur_file)
	{
		gfloop(cur_file, tmp, directory, hidden);
		cur_file = readdir(current);
	}
	closedir(current);
	return (buf);
}
