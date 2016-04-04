/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulongtooctal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:04 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:04:45 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulongtooctal(unsigned long long n)
{
	char				*ret;
	int					i;
	unsigned long long	tmp;

	tmp = n;
	i = 0;
	while (tmp > 7)
	{
		tmp = tmp / 8;
		i++;
	}
	ret = ft_strnew(i + 1);
	while (i >= 0)
	{
		tmp = n % 8;
		ret[i] = 48 + tmp;
		n = n / 8;
		i--;
	}
	return (ret);
}
