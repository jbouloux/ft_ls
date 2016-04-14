/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:50:22 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:50:24 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

static	int	get_padding_loop(t_files *tmp, int option)
{
	if (option == 1)
		return (ft_longlen((long)tmp->info->st_size));
	else if (option == 0)
		return (ft_longlen((long)tmp->info->st_nlink));
	else if (option == 2)
		return (ft_strlen((getpwuid(tmp->info->st_uid))->pw_name));
	else if (option == 3)
		return (ft_strlen((getgrgid(tmp->info->st_gid))->gr_name));
	else if (option == 4 && (S_ISCHR(tmp->info->st_mode) || \
		S_ISBLK(tmp->info->st_mode)))
		return (ft_longlen(get_major(tmp->info->st_rdev)));
	else if (option == 5 && (S_ISCHR(tmp->info->st_mode) || \
		S_ISBLK(tmp->info->st_mode)))
		return (ft_longlen(get_minor(tmp->info->st_rdev)));
	else
		return (0);
}

static int	get_padding(t_files *begin, int option)
{
	int		result;
	int		buf;
	t_files *tmp;

	tmp = begin;
	result = 0;
	buf = 0;
	while (tmp)
	{
		if (tmp->info)
		{
			buf = get_padding_loop(tmp, option);
			if (buf > result)
				result = buf;
		}
		tmp = tmp->next;
	}
	return (result);
}

int			*get_padtab(t_files *begin)
{
	int	*padtab;

	padtab = ft_createinttab(7);
	padtab[0] = get_padding(begin, 0);
	padtab[1] = get_padding(begin, 1);
	padtab[2] = get_padding(begin, 2);
	padtab[3] = get_padding(begin, 3);
	padtab[4] = get_padding(begin, 4);
	padtab[5] = get_padding(begin, 5);
	if (padtab[4] || padtab[5])
		padtab[6] = padtab[4] + padtab[5] + 3;
	return (padtab);
}

void		display_padding(long number, int padding)
{
	if (number == 0)
		padding--;
	else
		padding -= ft_longlen(number);
	if (padding == 0)
	{
		ft_putlong(number);
		return ;
	}
	while (padding-- > 0)
		ft_putchar(' ');
	ft_putlong(number);
}

void		display_paddingstr(char *str, int padding)
{
	padding -= ft_strlen(str);
	if (padding == 0)
	{
		ft_putstr(str);
		return ;
	}
	ft_putstr(str);
	while (padding-- > 0)
		ft_putchar(' ');
}
