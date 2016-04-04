/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:56 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:44:58 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunsint(unsigned int n)
{
	unsigned int	r;

	r = 0;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		r += 1;
	}
	ft_putchar(n % 10 + '0');
	return (r + 1);
}
