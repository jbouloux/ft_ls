/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 17:32:36 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 17:32:39 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct			s_dir
{
	char				*path;
	struct s_files		*files;
	char				*error;
	time_t				mtime;
	struct s_dir		*sousdir;
	struct s_dir		*next;
}						t_dir;

typedef struct			s_files
{
	char				*path;
	char				*name;
	struct stat			*info;
	struct s_files		*next;
}						t_files;

typedef struct			s_env
{
	struct s_dir		*argdir;
	struct s_dir		*dir;
	struct s_files		*files;
	int					*flags;
	int					multi;
	int					line;
}						t_env;

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

int						isdir(char *path);
int						isnavdir(char *dir);
int						check_dir(char *path);

t_files					*add_file(char *path);
t_dir					*add_dir(char *path);
char					*create_error(char *error, char *path);
char					*create_file_error(char *error, char *path);
char					*file_path(char *directory, char *name);

void					loop_display(t_dir *begin, t_env *env, int line);
void					display_fat_file(t_stat *file, char *name, char *path, \
						int *pad);
void					display_fat(t_dir *begin, t_env *env, int line);

void					free_list(t_dir *begin);
t_dir					*free_list_dir(t_dir *begin);
void					free_all(t_env *env);
t_files					*free_list_file(t_files *begin);

char					*get_last_word(char *str);
void					get_flags(char *arg, t_env *env);
void					get_file_name(t_files *begin);
int						get_major(dev_t st_rdev);
int						get_minor(dev_t st_rdev);

long					get_dirblock(t_files *begin);
time_t					get_time(char *path);
t_env					*init_env(void);
t_files					*get_solo_fl(t_files *filebegin, int argc, char **argv);
void					flag_error(t_env *env, char flag);

t_env					*pre_get_dir(t_env *env);
t_dir					*get_one_dir(t_dir *begin, int argc, char **argv);
t_dir					*get_argdir(int fl, int argc, char **argv, t_env *env);
t_dir					*get_dir_recu(t_dir *begin, char *newpath, t_env *env);
t_dir					*get_dir(char *path, t_env *env);

void					printfiles(t_dir *tmp);
t_env					*pre_get_files(t_dir *begin, t_env *env);
t_files					*get_files(t_dir *directory, int hidden);

int						*get_padtab(t_files *begin);
void					display_padding(long number, int padding);
void					display_paddingstr(char *str, int padding);

void					ft_print_rights(mode_t st_mode);
void					display_date(time_t date);
void					display_link(char *path);
void					display_major_minor(dev_t st_rdev, int *padtab);

t_files					*add_one_file(char *path);
void					display_solo(t_files *begin, t_env *env);
void					dsp_solo_list(t_files *begin, t_env *env, t_dir *dir);
void					display_simple(t_dir *begin, t_env *env, int line);

void					pick_sort(t_files *begin, int *flags);

void					sortlist(t_dir *begin, int *flags);

void					swap_dir(t_dir *aide, t_dir *tmp, t_dir *min);
void					swap_files(t_files *aide, t_files *tmp, t_files *min);

#endif
