#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void	pick_sort(t_files *begin, int *flags)
{
	if (!begin)
		return;
	if (flags[3])
		sort_rev_alpha(begin);
	else if (flags[4])
		sort_date(begin);
	else if (flags[5])
		sort_rev_date(begin);
	else
		sort_alpha(begin);
}

void sort_alpha(t_files *begin)
{
	t_files 	*tmp;
	t_files 	*tmp2;
	t_files 	*min;
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
		aide->name = tmp->name;
		aide->info = tmp->info;
		aide->path = tmp->path;
		tmp->name = min->name;
		tmp->info = min->info;
		tmp->path = min->path;
		min->name = aide->name;
		min->info = aide->info;
		min->path = aide->path;
		tmp = tmp->next;
	}
	free(aide);
}

void sort_rev_alpha(t_files *begin)
{
	t_files 	*tmp;
	t_files 	*tmp2;
	t_files 	*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_strcmp(tmp2->name, min->name) >= 0))
				min = tmp2;
			tmp2 = tmp2->next;
		}
		aide->name = tmp->name;
		aide->info = tmp->info;
		aide->path = tmp->path;
		tmp->name = min->name;
		tmp->info = min->info;
		tmp->path = min->path;
		min->name = aide->name;
		min->info = aide->info;
		min->path = aide->path;
		tmp = tmp->next;
	}
	free(aide);
}

void sort_date(t_files *begin)
{
	t_files 	*tmp;
	t_files 	*tmp2;
	t_files 	*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->info->st_mtime >= min->info->st_mtime)
				min = tmp2;
			tmp2 = tmp2->next;
		}
		aide->name = tmp->name;
		aide->info = tmp->info;
		aide->path = tmp->path;
		tmp->name = min->name;
		tmp->info = min->info;
		tmp->path = min->path;
		min->name = aide->name;
		min->info = aide->info;
		min->path = aide->path;
		tmp = tmp->next;
	}
	free(aide);
}

void sort_rev_date(t_files *begin)
{
	t_files 	*tmp;
	t_files 	*tmp2;
	t_files 	*min;
	t_files		*aide;

	tmp = begin;
	aide = (t_files *)malloc(sizeof(t_files));
	while (tmp->next)
	{
		min = tmp;
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp2->info->st_mtime <= min->info->st_mtime)
				min = tmp2;
			tmp2 = tmp2->next;
		}
		aide->name = tmp->name;
		aide->info = tmp->info;
		aide->path = tmp->path;
		tmp->name = min->name;
		tmp->info = min->info;
		tmp->path = min->path;
		min->name = aide->name;
		min->info = aide->info;
		min->path = aide->path;
		tmp = tmp->next;
	}
	free(aide);
}

















