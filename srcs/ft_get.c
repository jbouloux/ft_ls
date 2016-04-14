/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:49:40 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:49:43 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

char	*get_last_word(char *str)
{
	char	*tmp;
	int		i;
	int		ret;

	tmp = str;
	i = 0;
	while (*tmp)
	{
		i++;
		if (*tmp == '/')
			ret = i;
		tmp++;
	}
	return (ft_strdup(str + ret));
}

void	get_flags(char *arg, t_env *env)
{
	arg++;
	while (*arg)
	{
		if (*arg == 'l')
			env->flags[0] = 1;
		else if (*arg == 'R')
			env->flags[1] = 1;
		else if (*arg == 'a')
			env->flags[2] = 1;
		else if (*arg == 'r')
			env->flags[3] = 1;
		else if (*arg == 't')
			env->flags[4] = 1;
		else
			flag_error(env, *arg);
		arg++;
	}
	if (env->flags[3] && env->flags[4])
	{
		env->flags[3] = 0;
		env->flags[4] = 0;
		env->flags[5] = 1;
	}
}

void	get_file_name(t_files *begin)
{
	t_files *tmp;

	tmp = begin;
	while (tmp)
	{
		tmp->name = get_last_word(tmp->path);
		tmp = tmp->next;
	}
}

int		get_major(dev_t st_rdev)
{
	int major;

	major = st_rdev;
	while ((major / 256) > 0)
		major = major / 256;
	return (major);
}

int		get_minor(dev_t st_rdev)
{
	int minor;

	minor = st_rdev % 256;
	return (minor);
}
