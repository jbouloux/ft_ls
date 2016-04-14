/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_solo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:50:53 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:50:55 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

t_files		*add_one_file(char *path)
{
	t_files		*file;
	t_stat		*buf;
	char		*error;

	buf = (t_stat *)malloc(sizeof(t_stat));
	file = (t_files *)malloc(sizeof(t_files));
	if ((lstat(path, buf)) == -1)
	{
		free(buf);
		free(file);
		error = create_file_error(strerror(errno), path);
		ft_putstr(error);
		free(error);
		return (NULL);
	}
	file->path = ft_strdup(path);
	file->name = ft_strdup(path);
	file->info = buf;
	file->next = NULL;
	return (file);
}

void		display_solo(t_files *begin, t_env *env)
{
	t_files		*tmp;
	int			*padtab;

	tmp = begin;
	padtab = get_padtab(begin);
	pick_sort(tmp, env->flags);
	while (tmp)
	{
		if (!(env->flags[0]))
		{
			ft_putstr(tmp->path);
			ft_putchar('\n');
		}
		else
			display_fat_file(tmp->info, tmp->name, tmp->path, padtab);
		tmp = tmp->next;
	}
	begin = free_list_file(begin);
	free(padtab);
}

void		dsp_solo_list(t_files *begin, t_env *env, t_dir *dir)
{
	display_solo(begin, env);
	if (dir)
	{
		ft_putchar('\n');
		env->multi = 1;
		env->line = 1;
	}
}

void		display_simple(t_dir *begin, t_env *env, int line)
{
	t_dir		*tmpdir;
	t_files		*tmpfl;

	tmpdir = begin;
	if (line)
		ft_putchar('\n');
	if (env->multi)
	{
		ft_putstr(tmpdir->path);
		ft_putstr(":\n");
	}
	tmpfl = tmpdir->files;
	if (tmpdir->error)
		ft_putstr(tmpdir->error);
	else
	{
		get_file_name(tmpfl);
		pick_sort(tmpfl, env->flags);
		while (tmpfl)
		{
			ft_putstr(tmpfl->name);
			ft_putchar('\n');
			tmpfl = tmpfl->next;
		}
	}
}
