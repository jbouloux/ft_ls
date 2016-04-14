/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 18:51:34 by jbouloux          #+#    #+#             */
/*   Updated: 2016/04/13 18:51:36 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

int	main(int argc, char **argv)
{
	t_env		*env;
	int			flag;

	flag = 0;
	env = init_env();
	if (argc > 1 && argv[1][0] == '-' && argv[1][1])
	{
		get_flags(argv[1], env);
		flag = 1;
	}
	env->argdir = get_argdir(flag, argc, argv, env);
	if (!(env->argdir))
	{
		free_all(env);
		return (0);
	}
	sortlist(env->argdir, env->flags);
	if (argc > (flag + 2))
		env->multi = 1;
	env = pre_get_dir(env);
	free_all(env);
	return (0);
}
