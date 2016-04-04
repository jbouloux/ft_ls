/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttooctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouloux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:08:52 by jbouloux          #+#    #+#             */
/*   Updated: 2016/03/02 15:54:32 by jbouloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long ft_inttooctal (unsigned int n)
{
   unsigned long octal;
   unsigned long m;

   m = 1;
   octal = 0;
   while (n != 0)
   {
      octal += (n % 8) * m;
      m *= 10;
      n /= 8;
   }
   return (octal);
}