/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:50:02 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:50:05 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

t_env		*pre_get_dir(t_env *env)
{
	t_dir	*tmp;
	int		line;

	line = 0;
	tmp = env->argdir;
	while (tmp)
	{
		env->dir = add_dir(tmp->path);
		env->dir->sousdir = get_dir(env->dir->path, env);
		sortlist(env->dir, env->flags);
		pre_get_files(env->dir, env);
		if (env->dir->sousdir)
			env->multi = 1;
		loop_display(env->dir, env, line);
		line = 1;
		free_list(env->dir);
		tmp = tmp->next;
	}
	return (env);
}

t_dir		*get_one_dir(t_dir *begin, int argc, char **argv)
{
	t_dir *tmp;

	tmp = begin;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (check_dir(argv[argc - 1]))
		{
			tmp->next = add_dir(argv[argc - 1]);
			tmp->next->mtime = get_time(argv[argc - 1]);
		}
	}
	else
	{
		if (check_dir(argv[argc - 1]))
		{
			begin = add_dir(argv[argc - 1]);
			begin->mtime = get_time(argv[argc - 1]);
		}
	}
	return (begin);
}

t_dir		*get_argdir(int fl, int argc, char **argv, t_env *env)
{
	t_dir	*begin;
	t_files *filebegin;

	if (argc == 1 || (argc == 2 && fl))
		return (add_dir("./"));
	begin = NULL;
	filebegin = NULL;
	while (argc > fl + 1)
	{
		if ((isdir(argv[argc - 1])) <= 0)
			filebegin = get_solo_fl(filebegin, argc, argv);
		else
			begin = get_one_dir(begin, argc, argv);
		argc--;
	}
	if (filebegin)
		dsp_solo_list(filebegin, env, begin);
	return (begin);
}

t_dir		*get_dir_recu(t_dir *begin, char *newpath, t_env *env)
{
	t_dir *tmp;

	tmp = begin;
	if (!tmp)
	{
		begin = add_dir(newpath);
		begin->mtime = get_time(newpath);
		begin->sousdir = get_dir(begin->path, env);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_dir(newpath);
		tmp->next->mtime = get_time(newpath);
		tmp->next->sousdir = get_dir(tmp->next->path, env);
	}
	return (begin);
}

t_dir		*get_dir(char *path, t_env *env)
{
	DIR				*current;
	t_dirent		*cur_file;
	t_dir			*begin;
	char			*newpath;

	begin = NULL;
	current = opendir(path);
	if (!current)
		return (NULL);
	cur_file = readdir(current);
	while (env->flags[1])
	{
		if (!cur_file)
			break ;
		newpath = file_path(path, cur_file->d_name);
		if (isdir(newpath) && (cur_file->d_name[0] != '.' \
			|| env->flags[2]) && !isnavdir(cur_file->d_name))
			begin = get_dir_recu(begin, newpath, env);
		free(newpath);
		cur_file = readdir(current);
	}
	closedir(current);
	return (begin ? begin : NULL);
}
