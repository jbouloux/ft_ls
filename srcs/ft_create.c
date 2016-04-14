/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:49:09 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:49:12 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

t_files		*add_file(char *path)
{
	t_files	*new;

	if (!(new = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	new->path = ft_strdup(path);
	new->info = NULL;
	new->next = NULL;
	return (new);
}

t_dir		*add_dir(char *path)
{
	t_dir *new;

	if (!(new = (t_dir *)malloc(sizeof(t_dir))))
		return (NULL);
	new->path = ft_strdup(path);
	new->error = NULL;
	new->files = NULL;
	new->sousdir = NULL;
	new->next = NULL;
	return (new);
}

char		*create_error(char *error, char *path)
{
	char	*str;
	char	*name;

	name = get_last_word(path);
	str = ft_strjoin("ft_ls: ", name);
	str = ft_strrejoin(str, str, ": ");
	str = ft_strrejoin(str, str, error);
	str = ft_strrejoin(str, str, "\n");
	free(name);
	return (str);
}

char		*create_file_error(char *error, char *path)
{
	char	*str;

	str = ft_strjoin("ft_ls: ", path);
	str = ft_strrejoin(str, str, ": ");
	str = ft_strrejoin(str, str, error);
	str = ft_strrejoin(str, str, "\n");
	return (str);
}

char		*file_path(char *directory, char *name)
{
	char *path;

	if (directory[ft_strlen(directory) - 1] == '/')
		path = ft_strjoin(directory, name);
	else
	{
		path = ft_strjoin(directory, "/");
		path = ft_strrejoin(path, path, name);
	}
	return (path);
}
