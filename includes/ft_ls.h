#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct			s_list_dir
{
	char				*path;
	struct s_files		*files;
	char				*error;
	struct s_list_dir	*next;
}						t_list_dir;

typedef struct 			s_files
{
	char				*path;
	char				*name;
	struct stat			*info;
	struct s_files		*next;
}						t_files;

typedef struct			environment
{
	struct s_list_dir	*argdir;
	struct s_list_dir	*dir;
	struct s_files		*files;
	int					*flags;
	int					multi;
}						s_env;

typedef struct dirent	dirent;

int			*get_flags(char *arg, int *flags);
t_list_dir 	*add_dir(char *path);
t_list_dir 	*get_argdir(int flag, int argc, char **argv);
t_list_dir	*get_dir(char *path, s_env *env, t_list_dir	*first);
int 		isnavdir(char *dir);
t_list_dir 	*free_list_dir(t_list_dir *begin);
s_env		*pre_get_dir(s_env *env);
void		free_all(s_env *env);
s_env		*pre_get_files(s_env *env);
t_files		*get_files(t_list_dir *directory, int hidden);
char		*get_last_word(char *str);
t_files		*add_file(char *path);
char 		*file_path(char *directory, char *name);
void		display_simple(s_env *env);
t_files		*free_list_file(t_files *begin);
void		display_fat(s_env *env);
void		display_fat_file(struct stat *file, char *name, char *path, int *padtab);
void 		ft_file_type(mode_t st_mode);
void 		ft_print_rights(mode_t st_mode);
int 		get_padding(t_files *begin, int option);
int			*get_padtab(t_files *begin);
void		display_date(time_t date);
long		get_dirblock(t_files *begin);
void		display_padding(long number, int padding);
void		display_paddingstr(char *str, int padding);
t_files		*swapfiles(t_files *a);
int			cmpalpha(t_files *a, t_files *b);
int 		issort_alpha(t_files *begin);
void		get_file_name(t_files *begin);
t_files		*sort_by_alpha(t_files *begin);
void 		sort_alpha(t_files *begin);
void 		sort_rev_alpha(t_files *begin);
void		pick_sort(t_files *begin, int *flags);
void 		sort_date(t_files *begin);
void 		sort_rev_date(t_files *begin);
void		display_link(char *path);
void		display_major_minor(dev_t st_rdev, int *padtab);
int			get_major(dev_t st_rdev);
int			get_minor(dev_t st_rdev);
char		*create_error(char *error, char *path);
int			get_padding_loop(t_files *tmp, int option);
int			check_dir(char *path);

#endif