#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

s_env		*pre_get_dir(s_env *env)
{
	t_list_dir *tmp;
	t_list_dir *tmp2;

	env->dir = add_dir(env->argdir->path);
	env->dir->next = get_dir(env->dir->path, env, env->dir);
	tmp = env->argdir->next;
	while (tmp)
	{
		tmp2 = env->dir;
		while(tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = add_dir(tmp->path);
		tmp2->next->next = get_dir(tmp2->next->path, env, tmp2->next);
		tmp = tmp->next;
	}
	return (env);
}

t_list_dir 	*get_argdir(int flag, int argc, char **argv)
{
	t_list_dir *begin;
	t_list_dir *tmp;

	if (argc == 1 || (argc == 2 && flag))
	{
		begin = add_dir("./");
		return (begin);
	}
	begin = NULL;
	while (argc > flag + 1)
	{
		tmp = begin;
		if (tmp)
		{
			while (tmp->next)
				tmp = tmp->next;
			if (check_dir(argv[argc - 1]))
				tmp->next = add_dir(argv[argc - 1]);
		}
		else
		{
			if (check_dir(argv[argc - 1]))
				tmp = add_dir(argv[argc - 1]);
			begin = tmp;
		}
		argc--;
	}
	return (begin);
}

t_list_dir	*get_dir(char *path, s_env *env, t_list_dir	*first)
{
	DIR *current;
	struct dirent *cur_file;
	t_list_dir *tmp;
	t_list_dir *tmp2;

	tmp = first;
	tmp2 = tmp;
	current = opendir(path);
	if (!current)
		return (NULL);
	cur_file = readdir(current);
	while (env->flags[1])
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!cur_file)
			break;
		if (cur_file->d_type == 4 && (cur_file->d_name[0] != '.' \
			|| env->flags[2]) && !isnavdir(cur_file->d_name))
		{
			tmp->next = add_dir(cur_file->d_name);
			tmp = tmp->next;
			tmp->path = first->path[ft_strlen(first->path) - 1] != '/' ? \
			ft_strrejoin(tmp->path, "/", tmp->path) : tmp->path;
			tmp->path = ft_strrejoin(tmp->path, first->path, tmp->path);
			tmp->next = get_dir(tmp->path, env, tmp);
		}
		cur_file = readdir(current); 
	}
	closedir(current);
	return (tmp2->next ? tmp2->next : NULL);
}
