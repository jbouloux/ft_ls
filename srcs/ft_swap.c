/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:51:24 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:51:25 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void	swap_dir(t_dir *aide, t_dir *tmp, t_dir *min)
{
	aide->path = tmp->path;
	aide->error = tmp->error;
	aide->sousdir = tmp->sousdir;
	aide->mtime = tmp->mtime;
	tmp->path = min->path;
	tmp->error = min->error;
	tmp->sousdir = min->sousdir;
	tmp->mtime = min->mtime;
	min->path = aide->path;
	min->error = aide->error;
	min->sousdir = aide->sousdir;
	min->mtime = aide->mtime;
}

void	swap_files(t_files *aide, t_files *tmp, t_files *min)
{
	aide->name = tmp->name;
	aide->info = tmp->info;
	aide->path = tmp->path;
	tmp->name = min->name;
	tmp->info = min->info;
	tmp->path = min->path;
	min->name = aide->name;
	min->info = aide->info;
	min->path = aide->path;
}
