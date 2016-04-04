/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttohexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:08:52 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:54:32 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_inttohexa(unsigned long long n)
{
	char const	*base;
	char		res[16];
	int			i;
	int			j;
	char		*hexa;

	j = 0;
	hexa = ft_strnew(16);
	base = "0123456789abcdef";
	i = 15;
	while ((n / 16) > 0 || i >= 15)
	{
		res[i] = base[(n % 16)];
		n /= 16;
		i--;
	}
	res[i] = base[(n % 16)];
	while (i <= 15)
	{
		hexa[j] = res[i];
		i++;
		j++;
	}
	return (hexa);
}
