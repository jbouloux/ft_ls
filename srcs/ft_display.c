#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

void	display_simple(s_env *env)
{
	t_list_dir	*tmpdir;
	t_files		*tmpfl;

	tmpdir = env->dir;
	while (tmpdir)
	{
		if (env->multi || (tmpdir->next))
		{
			ft_putstr(tmpdir->path);
			ft_putstr(":\n");
		}
		tmpfl = tmpdir->files;
		get_file_name(tmpfl);
		pick_sort(tmpfl, env->flags);
		while (tmpfl)
		{
			ft_putstr(tmpfl->name);
			ft_putchar('\n');
			tmpfl = tmpfl->next;
		}
		if ((tmpdir = tmpdir->next))
			ft_putchar('\n');
	}
}

static void	dsp_fat_file2(struct stat *file, char *name, char *path, int *padtab)
{
	if (S_ISCHR(file->st_mode) || S_ISBLK(file->st_mode))
		display_major_minor(file->st_rdev, padtab);
	else
	{
		if (padtab[6])
		{
			display_padding(file->st_size, padtab[6]);
			ft_putchar(' ');
		}
		else
			display_padding(file->st_size, padtab[1]);
	}
	ft_putchar(' ');
	display_date(file->st_mtime);
	ft_putstr(name);
	if (((file->st_mode & S_IFMT) == S_IFLNK))
		display_link(path);
	ft_putchar('\n');
}

void	display_fat_file(struct stat *file, char *name, char *path, int *padtab)
{
	char *testacl;

	testacl = ft_strnew(256);
	if (!file || !name)
		return;
	ft_print_rights(file->st_mode);
	if (listxattr(path, testacl, 256, 0))
		ft_putstr("@ ");
	else
		ft_putstr("  ");
	free(testacl);
	display_padding(file->st_nlink, padtab[0]);
	ft_putchar(' ');
	display_paddingstr((getpwuid(file->st_uid))->pw_name, padtab[2]);
	ft_putstr("  ");
	display_paddingstr((getgrgid(file->st_gid))->gr_name, padtab[3]);
	ft_putstr("  ");
	dsp_fat_file2(file, name, path, padtab);
}

static t_list_dir *dsp_fat2(t_list_dir	*tmpdir, s_env *env)
{
	t_files		*tmpfl;
	int			*padtab;

	ft_putstr("total ");
	ft_putlong(get_dirblock(tmpdir->files));
	ft_putchar('\n');
	tmpfl = tmpdir->files;
	padtab = get_padtab(tmpfl);
	get_file_name(tmpfl);
	pick_sort(tmpfl, env->flags);
	while (tmpfl)
	{
		display_fat_file(tmpfl->info, tmpfl->name, tmpfl->path, padtab);
		tmpfl = tmpfl->next;
	}
	tmpdir = tmpdir->next;
	if (tmpdir)
		ft_putchar('\n');
	free(padtab);
	return (tmpdir);
}

void	display_fat(s_env *env)
{
	t_list_dir	*tmpdir;

	tmpdir = env->dir;
	while (tmpdir)
	{
		if (env->multi || (tmpdir->next))
		{
			ft_putstr(tmpdir->path);
			ft_putstr(":\n");
		}
		if (tmpdir->error)
		{
			ft_putstr(tmpdir->error);
			tmpdir = tmpdir->next;
		}
		else
			tmpdir = dsp_fat2(tmpdir, env);
	}
}