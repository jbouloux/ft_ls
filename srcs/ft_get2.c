/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:49:51 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:49:54 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

long		get_dirblock(t_files *begin)
{
	t_files	*tmp;
	long	result;

	result = 0;
	tmp = begin;
	while (tmp)
	{
		result += tmp->info->st_blocks;
		tmp = tmp->next;
	}
	return (result);
}

time_t		get_time(char *path)
{
	t_stat		*buf;
	time_t		mtime;

	buf = (t_stat *)malloc(sizeof(t_stat));
	lstat(path, buf);
	mtime = buf->st_mtime;
	free(buf);
	return (mtime);
}

t_env		*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	env->flags = ft_createinttab(6);
	env->multi = 0;
	env->line = 0;
	env->argdir = NULL;
	return (env);
}

t_files		*get_solo_fl(t_files *filebegin, int argc, char **argv)
{
	t_files	*filetmp;

	filetmp = filebegin;
	if (!filetmp)
		filebegin = add_one_file(argv[argc - 1]);
	else
	{
		while (filetmp->next)
			filetmp = filetmp->next;
		filetmp->next = add_one_file(argv[argc - 1]);
	}
	return (filebegin);
}

void		flag_error(t_env *env, char flag)
{
	free(env->flags);
	free(env);
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putstr("usage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}
