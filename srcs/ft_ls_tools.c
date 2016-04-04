#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

int	*get_flags(char *arg, int *flags)
{
	arg++;
	while (*arg)
	{
		if (*arg == 'l')
			flags[0] = 1;
		else if (*arg == 'R')
			flags[1] = 1;
		else if (*arg == 'a')
			flags[2] = 1;
		else if (*arg == 'r')
			flags[3] = 1;
		else if (*arg == 't')
			flags[4] = 1;
		arg++;
	}
	if (flags[3] && flags[4])
	{
		flags[3] = 0;
		flags[4] = 0;
		flags[5] = 1;
	}
	return (flags);
}

t_list_dir *add_dir(char *path)
{
	t_list_dir *new;

	if (!(new = (t_list_dir *)malloc(sizeof(t_list_dir))))
		return (NULL);
	new->path = ft_strdup(path);
	new->error = NULL;
	new->files = NULL;
	new->next = NULL;
	return (new);
}

int isnavdir(char *dir)
{
	if (dir[0] == '.' && !dir[1])
		return (1);
	else if (dir[0] == '.' && dir[1] == '.' && !dir[2])
		return (1);
	else
		return (0);
}

t_list_dir *free_list_dir(t_list_dir *begin)
{
	t_list_dir *tmp;

	while (begin)
    {
        tmp = begin;
        begin = begin->next;
        free(tmp->path);
        tmp->files = free_list_file(tmp->files);
        if (tmp->error)
        	free(tmp->error);
        free(tmp);
    }
    return (NULL);
}

void	free_all(s_env *env)
{
	env->argdir = free_list_dir(env->argdir);
	env->dir = free_list_dir(env->dir);
	free(env->flags);
	free(env);
}
