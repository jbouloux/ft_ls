#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

s_env		*pre_get_files(s_env *env)
{
	t_list_dir		*tmp;

	tmp = env->dir;
	while (tmp)
	{
		tmp->files = get_files(tmp, env->flags[2]);
		tmp = tmp->next;
	}
	return (env);
}

static void		gfloop(dirent *file, t_files *tmp, t_list_dir *rep, int hidden)
{
	char *path;

	if (file->d_name[0] != '.' || hidden)
	{
		while (tmp->next)
			tmp = tmp->next;
		path = file_path(rep->path, file->d_name); 
		tmp->next = add_file(path);
		tmp->next->info = (struct stat *)malloc(sizeof(struct stat));
		lstat(path, tmp->next->info);
		tmp = tmp->next;
		free(path);
	}
}

static dirent	*gfverif(DIR *current, t_list_dir *directory, int hidden)
{
	dirent		*cur_file;

	if (!current)
	{
		directory->error = create_error(strerror(errno), directory->path);
		return (NULL);
	}
	if (!(cur_file = readdir(current)))
	{
		closedir(current);
		return (NULL);
	}
	while (cur_file->d_name[0] == '.' && !hidden)
	{
		cur_file = readdir(current);
		if (!cur_file)
		{
			closedir(current);
			return (NULL);
		}
	}
	return (cur_file ? cur_file : NULL);
}

t_files			*get_files(t_list_dir *directory, int hidden)
{
	DIR 		*current;
	dirent		*cur_file;
	t_files		*buf;
	t_files		*tmp;
	char		*path;

	current = opendir(directory->path);
	if (!(cur_file = gfverif(current, directory, hidden)))
		return (NULL);
	path = file_path(directory->path, cur_file->d_name);
	buf = add_file(path);
	buf->info = (struct stat *)malloc(sizeof(struct stat));
	lstat(path, buf->info);
	cur_file = readdir(current);
	tmp = buf;
	free(path);
	while (cur_file)
	{
		gfloop(cur_file, tmp, directory, hidden);
		cur_file = readdir(current);
	}
	closedir(current);
	return (buf);
}
