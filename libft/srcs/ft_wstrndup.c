/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:17:06 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:44:14 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrndup(wchar_t *s1, int n)
{
	wchar_t		*dest;
	int			i;

	i = 0;
	if (ft_wstrlen(s1) >= n)
		dest = ft_wstrnew(n);
	else
		dest = ft_wstrnew(ft_wstrlen(s1));
	while (s1[i] != '\0' && n > 0)
	{
		if (n >= ft_wcharlen(s1[i]))
		{
			dest[i] = s1[i];
			n -= ft_wcharlen(s1[i]);
			i++;
		}
		else
		{
			n = 0;
			dest[i + 1] = '\0';
		}
	}
	return (dest);
}
