#include "../includes/ft_ls.h"
#include "../libft/includes/libft.h"

long	get_dirblock(t_files *begin)
{
	t_files	*tmp;
	long	result;

	result = 0;
	tmp = begin;
	while (tmp)
	{
		result += tmp->info->st_blocks;
		tmp = tmp->next;
	}
	return (result);
}

void	display_date(time_t date)
{
	char	*str1;
	char	*str2;
	time_t	actualtime;

	actualtime = time(0);
	str1 = ctime(&date);
	if ((actualtime - 15778463) > date || actualtime < date)
	{
		str2 = ft_strnew(6);
		str2 = ft_strsub(str1, 20, 4);
		str1 = ft_strsub(str1, 4, 6);
		str1 = ft_strjoin(str1, "  ");
		str1 = ft_strjoin(str1, str2);
		free(str2);
	}
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	str1[0] += 32;
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void	get_file_name(t_files *begin)
{
	t_files *tmp;

	tmp = begin;
	while (tmp)
	{
		tmp->name = get_last_word(tmp->path);
		tmp = tmp->next;
	}
}

void	display_padding(long number, int padding)
{
	if (number == 0)
		padding--;
	else
		padding -= ft_longlen(number);
	if (padding == 0)
	{
		ft_putlong(number);
		return;
	}
	while (padding-- > 0)
		ft_putchar(' ');
	ft_putlong(number);
}

void	display_paddingstr(char *str, int padding)
{
	padding -= ft_strlen(str);
	if (padding == 0)
	{
		ft_putstr(str);
		return;
	}
	ft_putstr(str);
	while (padding-- > 0)
		ft_putchar(' ');
}