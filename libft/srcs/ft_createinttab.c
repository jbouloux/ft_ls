/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createinttab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:21:04 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 14:09:18 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_createinttab(int n)
{
	int i;
	int *tab;

	tab = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i <= n - 1)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}