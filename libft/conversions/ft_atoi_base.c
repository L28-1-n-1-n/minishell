/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:16:41 by hlo               #+#    #+#             */
/*   Updated: 2019/11/15 12:37:56 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_base(const char c, int base)
{
	char	d;
	int		i;

	i = 0;
	d = ft_toupper(c);
	while (i < base)
	{
		if (i < 10)
		{
			if (d == '0' + i)
				return (1);
		}
		else if (i >= 10)
		{
			if (d == 'A' + i - 10)
				return (1);
		}
		i++;
	}
	return (0);
}

int			ft_atoi_base(const char *str, int base)
{
	int	res;
	int	isneg;

	if (base <= 1 || base > 36)
		return (0);
	res = 0;
	isneg = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		isneg++;
	if (*str == '-' || *str == '+')
		str++;
	while (in_base(*str, base))
	{
		if (*str <= '9')
			res = res * base + (*str - 48);
		else if (*str >= 97)
			res = res * base + (*str - 87);
		else if (*str >= 65)
			res = res * base + (*str - 55);
		str++;
	}
	return (isneg ? -res : res);
}
