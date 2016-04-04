/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:25 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:56:00 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsintlen(unsigned long n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
