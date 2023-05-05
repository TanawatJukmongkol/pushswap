/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:04:13 by tjukmong          #+#    #+#             */
/*   Updated: 2023/02/27 20:50:34 by tjukmong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converts array of char (numbers ofcourse) to int
// 1) trim the white spaces at the front.
// 2) change to negative if '-' was found.
// 3) trim '+'.
// 4) loop through the numbers and add to nbr, if no
//	  numbers found, break.

long	ft_atol(const char *nptr)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\a' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr)
	{
		if (*nptr >= '0' && *nptr <= '9')
			nbr = (nbr * 10) + (*nptr - '0');
		else
			break ;
		nptr++;
	}
	return (sign * nbr);
}
