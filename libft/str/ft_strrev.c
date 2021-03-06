/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:      hlo <hlo@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:38:27 by hlo               #+#    #+#             */
/*   Updated: 2019/11/15 12:52:52 by hlo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

void	ft_strrev(char *s)
{
	char	*end;

	end = s + (ft_strlen(s) - 1);
	while (s < end)
	{
		*s ^= *end;
		*end ^= *s;
		*s ^= *end;
		s++;
		end--;
	}
}
