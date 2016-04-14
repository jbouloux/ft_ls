/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:49:19 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:49:21 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void			loop_display(t_dir *begin, t_env *env, int line)
{
	t_dir *tmp;

	tmp = begin;
	while (tmp)
	{
		if (!(env->flags[0]))
		{
			display_simple(tmp, env, line);
			line = 1;
		}
		else
		{
			display_fat(tmp, env, line);
			line = 1;
		}
		if (tmp->sousdir)
			loop_display(tmp->sousdir, env, line);
		tmp = tmp->next;
	}
}

static void		dsp_fat_file2(t_stat *file, char *name, char *path, int *padtab)
{
	if (S_ISCHR(file->st_mode) || S_ISBLK(file->st_mode))
		display_major_minor(file->st_rdev, padtab);
	else
	{
		if (padtab[6])
			display_padding(file->st_size, padtab[6]);
		else
			display_padding(file->st_size, padtab[1]);
	}
	ft_putchar(' ');
	display_date(file->st_mtime);
	ft_putstr(name);
	if (((file->st_mode & S_IFMT) == S_IFLNK))
		display_link(path);
	ft_putchar('\n');
}

void			display_fat_file(t_stat *file, char *name, char *path, int *pad)
{
	char *testacl;

	testacl = ft_strnew(256);
	if (!file || !name)
		return ;
	ft_print_rights(file->st_mode);
	if (listxattr(path, testacl, 256, 0) && ((file->st_mode & S_IFMT) \
		!= S_IFLNK) && ((file->st_mode & S_IFMT) != S_IFBLK) && \
		((file->st_mode & S_IFMT) != S_IFCHR))
		ft_putstr("@ ");
	else if ((acl_get_file(path, ACL_TYPE_EXTENDED)) != 0)
		ft_putstr("+ ");
	else
		ft_putstr("  ");
	free(testacl);
	display_padding(file->st_nlink, pad[0]);
	ft_putchar(' ');
	display_paddingstr((getpwuid(file->st_uid))->pw_name, pad[2]);
	ft_putstr("  ");
	display_paddingstr((getgrgid(file->st_gid))->gr_name, pad[3]);
	ft_putstr("  ");
	dsp_fat_file2(file, name, path, pad);
}

static t_dir	*dsp_fat2(t_dir *tmpdir, t_env *env)
{
	t_files		*tmpfl;
	int			*padtab;

	env->line = 1;
	if (tmpdir->files)
	{
		ft_putstr("total ");
		ft_putlong(get_dirblock(tmpdir->files));
		ft_putchar('\n');
	}
	tmpfl = tmpdir->files;
	padtab = get_padtab(tmpfl);
	get_file_name(tmpfl);
	pick_sort(tmpfl, env->flags);
	while (tmpfl)
	{
		display_fat_file(tmpfl->info, tmpfl->name, tmpfl->path, padtab);
		tmpfl = tmpfl->next;
	}
	free(padtab);
	return (tmpdir);
}

void			display_fat(t_dir *begin, t_env *env, int line)
{
	t_dir	*tmpdir;

	tmpdir = begin;
	if (line)
		ft_putchar('\n');
	if (env->multi)
	{
		ft_putstr(tmpdir->path);
		ft_putstr(":\n");
	}
	if (tmpdir->error)
	{
		ft_putstr(tmpdir->error);
		tmpdir = tmpdir->next;
	}
	else
		tmpdir = dsp_fat2(tmpdir, env);
}
