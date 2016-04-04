/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:27:56 by jbouloux          #+#    #+#             */
/*   Updated: 2015/11/28 17:28:36 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(int size)
{
	wchar_t	*str;
	int		i;

	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size + 1)
		str[i++] = '\0';
	return (str);
}