/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:55 by jbouloux          #+#    #+#             */
/*   Updated: 2015/11/28 17:19:21 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int					i;
	unsigned char		*tmp;
	unsigned const char *tmp2;

	tmp = dst;
	tmp2 = src;
	i = 0;
	while (n > 0 && tmp2[i] != (unsigned char)c)
	{
		tmp[i] = tmp2[i];
		n--;
		i++;
	}
	if (tmp2[i] == (unsigned char)c && n > 0)
	{
		tmp[i] = (unsigned char)c;
		return (tmp + i + 1);
	}
	else
	{
		return (NULL);
	}
}
