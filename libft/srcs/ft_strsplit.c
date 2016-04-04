/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 03:33:00 by jbouloux          #+#    #+#             */
/*   Updated: 2015/12/14 13:26:48 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**strtab;
	int		i;
	int		len;

	i = 0;
	if (!(strtab = ft_memalloc(sizeof(strtab) * ft_word_count(s, c) + 1)))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (*(s + len) != c && *(s + len) != '\0')
			len++;
		if (len)
		{
			strtab[i] = ft_strsub(s, 0, len);
			i++;
		}
		s += len;
	}
	strtab[i] = NULL;
	return (strtab);
}
