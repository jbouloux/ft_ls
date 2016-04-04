/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:08:34 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 16:11:13 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_adrtostr(void const *p)
{
	unsigned long long	adr;
	char				*adrstr;
	char				*dest;

	adr = (unsigned long long)p;
	adrstr = ft_inttohexa(adr);
	dest = ft_strjoin("0x", adrstr);
	free(adrstr);
	return (dest);
}
