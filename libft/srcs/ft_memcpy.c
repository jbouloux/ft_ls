/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:55 by jbouloux          #+#    #+#             */
/*   Updated: 2015/11/28 17:19:42 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	unsigned char		*tmp;
	unsigned const char *tmp2;

	tmp = dst;
	tmp2 = src;
	i = 0;
	while (n > 0)
	{
		tmp[i] = tmp2[i];
		n--;
		i++;
	}
	return (dst);
}
