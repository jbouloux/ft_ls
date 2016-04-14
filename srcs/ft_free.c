/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:49:29 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 19:32:31 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void		free_list(t_dir *begin)
{
	t_dir	*tmp;

	tmp = begin;
	while (tmp->next)
	{
		if (tmp->sousdir)
			free_list(tmp->sousdir);
		else
			tmp = tmp->next;
	}
	if (!tmp)
		return ;
	if (!tmp->next)
		free_list_dir(begin);
}

t_dir		*free_list_dir(t_dir *begin)
{
	t_dir *tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp->path);
		tmp->files = free_list_file(tmp->files);
		if (tmp->error)
			free(tmp->error);
		if (tmp->sousdir)
			free_list_dir(tmp->sousdir);
		free(tmp);
	}
	return (NULL);
}

void		free_all(t_env *env)
{
	env->argdir = free_list_dir(env->argdir);
	free(env->flags);
	free(env);
}

t_files		*free_list_file(t_files *begin)
{
	t_files *tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp->path);
		free(tmp->name);
		if (tmp->info)
			free(tmp->info);
		free(tmp);
	}
	return (NULL);
}
