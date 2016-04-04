/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <jonathan.bouloux@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:18:19 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:55:17 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int	result;
	int	isneg;

	result = 0;
	isneg = 0;
	while (*str == ' ' || ft_isescaped(*str))
		str++;
	if (*str == '-' || *str == '+')
		isneg = (*(str++) == '-') ? 1 : 0;
	while (*str && ft_isdigit(*str))
		result = result * 10 + (*(str++) - 48);
	return (isneg ? result * -1 : result);
}
