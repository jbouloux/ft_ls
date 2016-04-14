/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:51:03 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:51:05 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

static	void	sort_alpha(t_files *begin)
{
	t_files		*tmp;
	t_files		*tmp2;
	t_files		*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_strcmp(tmp2->name, min->name) < 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_files(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

static	void	sort_rev_alpha(t_files *begin)
{
	t_files		*tmp;
	t_files		*tmp2;
	t_files		*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_strcmp(tmp2->name, min->name) > 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_files(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

static	void	sort_date(t_files *begin)
{
	t_files		*tmp;
	t_files		*tmp2;
	t_files		*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((tmp2->info->st_mtime > min->info->st_mtime))
				min = tmp2;
			else if ((tmp2->info->st_mtime == min->info->st_mtime) && \
				(ft_strcmp(tmp2->name, min->name) < 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_files(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

static	void	sort_rev_date(t_files *begin)
{
	t_files		*tmp;
	t_files		*tmp2;
	t_files		*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->info->st_mtime < min->info->st_mtime)
				min = tmp2;
			else if ((tmp2->info->st_mtime == min->info->st_mtime) && \
				(ft_strcmp(tmp2->name, min->name) > 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		swap_files(aide, tmp, min);
		tmp = tmp->next;
	}
	free(aide);
}

void			pick_sort(t_files *begin, int *flags)
{
	if (!begin)
		return ;
	if (flags[3])
		sort_rev_alpha(begin);
	else if (flags[4])
		sort_date(begin);
	else if (flags[5])
		sort_rev_date(begin);
	else
		sort_alpha(begin);
}
