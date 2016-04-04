#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

int main(int argc, char **argv)
{
	s_env		*env;
	int			flag;

	flag = 0;
	env = (s_env *)malloc(sizeof(s_env));
	env->flags = ft_createinttab(6);
	env->multi = 0;
	if (argc > 1 && argv[1][0] == '-' && argv[1][1])
	{
		env->flags = get_flags(argv[1], env->flags);
		flag = 1;
	}
	env->argdir = get_argdir(flag, argc, argv);
	if (!(env->argdir))
		return (0);
	if (argc > (flag + 2))
		env->multi = 1;
	env = pre_get_dir(env);
	env = pre_get_files(env);
	if (!(env->flags[0]))
		display_simple(env);
	else
		display_fat(env);
	free_all(env);
	return (0);
}
