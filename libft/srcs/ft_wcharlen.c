/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:18:36 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 14:18:37 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharlen(wchar_t wchar)
{
	int		len;

	len = 0;
	if (wchar < 0x80)
		len = 1;
	else if (wchar < 0x0800)
		len = 2;
	else if (wchar < 0x010000)
		len = 3;
	else if (wchar < 0x110000)
		len = 4;
	return (len);
}
