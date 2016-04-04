/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:17:37 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 14:17:39 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s1, size_t n)
{
	char	*dest;
	int		i;

	i = 0;
	if (ft_strlen(s1) >= n)
	{
		if (!(dest = (char *)malloc(sizeof(char) * n + 1)))
			return (NULL);
	}
	else
	{
		if (!(dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
			return (NULL);
	}
	while (s1[i] != '\0' && i < (int)n)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
