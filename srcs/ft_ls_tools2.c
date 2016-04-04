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

t_files	*add_file(char *path)
{
	t_files	*new;

	if (!(new = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	new->path = ft_strdup(path);
	new->info = NULL;
	new->next = NULL;
	return (new);
}

char	*file_path(char *directory, char *name)
{
	char *path;

	path = ft_strjoin(directory, "/");
	path = ft_strrejoin(path, path, name);
	return (path);
}

t_files	*free_list_file(t_files *begin)
{
	t_files *tmp;

	while (begin)
    {
        tmp = begin;
        begin = begin->next;
        free(tmp->path);
        free(tmp->name);
        free(tmp->info);
        free(tmp);
    }
    return (NULL);
}

int	*get_padtab(t_files *begin)
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