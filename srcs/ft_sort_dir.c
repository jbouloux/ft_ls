/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:51:13 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:51:16 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

static	void	sort_date_dir(t_dir *begin)
{
	t_dir	*tmp;
	t_dir	*tmp2;
	t_dir	*min;
	t_dir	*aide;

	tmp = begin;
	aide = (t_dir *)malloc(sizeof(t_dir));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->mtime > min->mtime)
				min = tmp2;
			else if ((tmp2->mtime == min->mtime) && \
				(ft_strcmp(tmp2->path, min->path) < 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_dir(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

static	void	sort_rev_date_dir(t_dir *begin)
{
	t_dir	*tmp;
	t_dir	*tmp2;
	t_dir	*min;
	t_dir	*aide;

	tmp = begin;
	aide = (t_dir *)malloc(sizeof(t_dir));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->mtime < min->mtime)
				min = tmp2;
			else if ((tmp2->mtime == min->mtime) && \
				(ft_strcmp(tmp2->path, min->path) > 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_dir(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

static	void	sort_alpha_dir(t_dir *begin)
{
	t_dir	*tmp;
	t_dir	*tmp2;
	t_dir	*min;
	t_dir	*aide;

	tmp = begin;
	aide = (t_dir *)malloc(sizeof(t_dir));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_strcmp(tmp2->path, min->path) < 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_dir(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

static	void	sort_rev_alpha_dir(t_dir *begin)
{
	t_dir	*tmp;
	t_dir	*tmp2;
	t_dir	*min;
	t_dir	*aide;

	tmp = begin;
	aide = (t_dir *)malloc(sizeof(t_dir));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_strcmp(tmp2->path, min->path) >= 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_dir(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

void			sortlist(t_dir *begin, int *flags)
{
	t_dir *tmp;

	tmp = begin;
	if (flags[4])
		sort_date_dir(tmp);
	else if (flags[5])
		sort_rev_date_dir(tmp);
	else if (flags[3])
		sort_rev_alpha_dir(tmp);
	else
		sort_alpha_dir(tmp);
	while (tmp)
	{
		if (tmp->sousdir)
			sortlist(tmp->sousdir, flags);
		tmp = tmp->next;
	}
}
